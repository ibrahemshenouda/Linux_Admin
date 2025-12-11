#include <iostream>
#include <fcntl.h>
#include <unistd.h>
#include <cstring>

int main()
{
	/*Flags
		1- O_RDWR  ----> open file for reading and writing
		2- O_CREAT ----> create file if not exist
		3- O_TRUNC ----> remove any data form file if exist*/

	/*Permissions
		1- S_IRUSR -----> Stat Inode Read USR (read permission for owner)
		2- S_IWUSR -----> State Inode Write USR (write permission for owner)
			*/

	const char *filename = "cpp_test.txt";
	int fd = open(filename, O_RDWR | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
	// if open() filed :
	if (fd == -1)
	{
		perror("open");
		return 1;
	}

	ssize_t bytes_written = write(fd, "Hello linux", strlen("Hello linux"));
	// if write() filed :
	if (bytes_written == -1)
	{
		perror("write");
		close(fd);
		return 1;
	}

	// set pointer to the begining of file to read
	if (lseek(fd, 0, SEEK_SET) == -1)
	{
		perror("lseek");
		close(fd);
		return 1;
	}

	char buffer[128];
	ssize_t bytes_read = read(fd, buffer, sizeof(buffer) - 1);
	if (bytes_read == -1)
	{
		perror("read");
		close(fd);
		return 1;
	}

	buffer[bytes_read] = '\0';
	std::cout << "Read from file: " << buffer << "\n";

	if (close(fd) == -1)
	{
		perror("close");
		return 1;
	}
	return 0;
}