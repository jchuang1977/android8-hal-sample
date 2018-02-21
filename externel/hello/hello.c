
#include <stdio.h>
#include <unistd.h>  
#include <stdlib.h>  
#include <fcntl.h>  
#define DEVICE_NAME "/dev/hello"
int main(int argc, char** argv)
{
	int fd = -1;
	int val = 0;
	int write_val = 0;
	if (argc < 2 )
	{
		printf("Usage: hello write_value\n");
		return -1 ;
	}
	else
	{
		write_val = atoi(argv[1]);
	}
	
	fd = open(DEVICE_NAME, O_RDWR);
	if(fd == -1) {
		printf("Failed to open device %s.\n", DEVICE_NAME);
		return -1;
	}
	
	printf("Read original value:\n");
	read(fd, &val, sizeof(val));
	printf("%d.\n\n", val);
	
	//val = 5;
	printf("Write value %d to %s.\n\n", write_val, DEVICE_NAME);
        write(fd, &write_val, sizeof(write_val));
	
	printf("Read the value again:\n");
        read(fd, &val, sizeof(val));
        printf("%d.\n\n", val);
	close(fd);
	return 0;
}
