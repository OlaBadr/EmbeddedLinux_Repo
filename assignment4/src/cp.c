#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>


void cp(char *argv[])
{

    char buf[1000];

    int fd1 = open(argv[2], O_RDONLY, 0644);
    int fd2 = open(argv[3], O_CREAT | O_WRONLY | O_TRUNC, 0644);

    read(fd1, buf, sizeof(buf));

    int size = 0;

    while (buf[size] != '\0') {
	size++;

    }
    write(fd2, buf, size);

    close(fd1);
    close(fd2);

}
