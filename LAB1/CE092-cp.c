// Implementation of basic cp command using system calls
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/types.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    int n;
    char buff[100000];
    if (argc == 1 || argc == 2)
    {
        write(1, "too less argument\n", 18);
    }
    else
    {
        int fdsrc, fddest;
        fdsrc = open(argv[1], O_RDONLY);
        if (fdsrc == 2)
        {
            write(1, "source file doesn't exists\n", 27);
            return 0;
        }
        fddest = open(argv[2], O_RDWR | O_CREAT);
        n = read(fdsrc, buff, sizeof(buff));
        write(fddest, buff, n);
        close(fddest);
        close(fdsrc);
    }
    return 0;
}
