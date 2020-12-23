/*
* @Author: nevil
* @Date:   2020-07-31 14:25:06
* @Last Modified by:   nevil
* @Last Modified time: 2020-07-31 14:28:46
*/
#include<stdio.h>
#include<dirent.h>
#include<sys/types.h>
#include<string.h>
#include<stdlib.h>

void ps_command(int argc, char *argv[])
{
	char mainPath[100];
	DIR *dirp = opendir("/proc/");
	struct dirent *d;

	int pid;
	char cmd[100];
	char state;
	int ppid;
	char state1[20];


	if (dirp == NULL)
	{
		fprintf(stderr, "can not open directory : %s\n", mainPath);
		return;
	}

	// foramating condition accroding to provided arguments
	if (argc == 2)
	{
		if (!strcmp(argv[1], "--more"))
			printf("%6s %30s %10s %10s\n", "PID", "COMMNAD", "PPID", "STATE");
	}
	else
		printf("%6s %30s\n", "PID", "COMMNAD");


	while (d = readdir(dirp))
	{
		if (strcmp(d->d_name, ".") != 0 && strcmp(d->d_name, "..") != 0)
		{
			if (d->d_type == DT_DIR && atoi(d->d_name) > 0)
			{
				// path generation
				strcpy(mainPath, "/proc/");
				strcat(mainPath, d->d_name);
				strcat(mainPath, "/stat");

				FILE *fp = fopen(mainPath, "r");
				if (fp == NULL)
					continue;

				switch (state)
				{
					case 'R': strcpy(state1, "Running"); // Running state
								break;
					case 'S': strcpy(state1, "Intr Wait"); // Interruptible wait state
								break;
					case 'D': strcpy(state1, "Unintr wait"); // Uninterruptible state
								break;
					case 'Z': strcpy(state1, "Zombie"); // Zombie state
								break;
					case 'T': strcpy(state1, "Traced"); // Traced State
								break;
					default: strcpy(state1, "Paging");	// Paging State
				}

				fscanf(fp, "%d\t%s\t%c\t%d", &pid, cmd, &state, &ppid);

				printf("%6d %30s ", pid, cmd);

				if (argc == 2)
				{
					if (!strcmp(argv[1], "--more"))
						printf("%6d %13s", ppid, state1);
				}

				printf("\n");
				fclose(fp);
			}
		}

	}
	closedir(dirp);
}



int main(int argc, char *argv[])
{
	ps_command(argc, argv);
	return 0;
}


/*
	This programe simulate the behaviour of PS command in linux.
	You can run this program in two diff ways.
	1) ./a.out 
	-> prints PID , and COMMAND NAME

	2) ./a.out --more 
	-> prints PID, COMMAND, STATE AND PPID.
*/