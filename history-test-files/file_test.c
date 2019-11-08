
#include <stdio.h>
#include <sys/types.h>

#include <sys/stat.h>


int dm_check_file_is_smlink(const char *path)
{
    struct stat s_buf;
    memset(&s_buf, 0x00, sizeof(s_buf));
    lstat(path, &s_buf);
    return S_ISLNK(s_buf.st_mode);
}


int main()
{

    if(dm_check_file_is_smlink(""))
    {
    
    }
}

