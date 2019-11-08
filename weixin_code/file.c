#include <stdio.h>
#include <string.h>
 
int main()
{
   FILE *fp;
   char *msg = "hello world";
   char buffer[20];
 
   /* 打开文件用于读写 */
   fp = fopen("test.txt", "w+");
 
   /* 写入数据到文件 */
   fwrite(msg, strlen(msg) + 1, 1, fp);
 
   /* 移动到文件的开头 */
   fseek(fp, 0, SEEK_SET);
 
   /* 读取并显示数据 */
   fread(buffer, strlen(msg) + 1, 1, fp);
   printf("%s\n", buffer);
   
   /* 刷新缓存 */
   fsync(fileno(fp));
   fclose(fp);
   
   return(0);
}
