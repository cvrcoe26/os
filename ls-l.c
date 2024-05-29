#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>
#include <sys/stat.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>

int main(int argc, char *argv[])
{
    DIR *dir;
    struct dirent *entry;
    struct stat fileStat;
    struct passwd *pw;
    struct group *gr;
    char buffer[1024];

    if (argc != 2)
    {
        printf("Usage: %s <directory>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if ((dir = opendir(argv[1])) == NULL)
    {
        perror("opendir");
        exit(EXIT_FAILURE);
    }

    while ((entry = readdir(dir)) != NULL)
    {
        sprintf(buffer, "%s/%s", argv[1], entry->d_name);

        if (stat(buffer, &fileStat) < 0)
        {
            perror("stat");
            continue;
        }

        printf((S_ISDIR(fileStat.st_mode)) ? "d" : "-");
        printf((fileStat.st_mode & S_IRUSR) ? "r" : "-");
        printf((fileStat.st_mode & S_IWUSR) ? "w" : "-");
        printf((fileStat.st_mode & S_IXUSR) ? "x" : "-");
        printf((fileStat.st_mode & S_IRGRP) ? "r" : "-");
        printf((fileStat.st_mode & S_IWGRP) ? "w" : "-");
        printf((fileStat.st_mode & S_IXGRP) ? "x" : "-");
        printf((fileStat.st_mode & S_IROTH) ? "r" : "-");
        printf((fileStat.st_mode & S_IWOTH) ? "w" : "-");
        printf((fileStat.st_mode & S_IXOTH) ? "x" : "-");
        printf(" ");

        printf("%ld ", (long)fileStat.st_nlink);

        if ((pw = getpwuid(fileStat.st_uid)) != NULL)
            printf("%s ", pw->pw_name);
        else
            printf("%d ", fileStat.st_uid);

        if ((gr = getgrgid(fileStat.st_gid)) != NULL)
            printf("%s ", gr->gr_name);
        else
            printf("%d ", fileStat.st_gid);

        printf("%lld ", (long long)fileStat.st_size);

        strftime(buffer, sizeof(buffer), "%b %d %H:%M", localtime(&fileStat.st_mtime));
        printf("%s ", buffer);

        printf("%s\n", entry->d_name);
    }

    closedir(dir);
    return 0;
}
