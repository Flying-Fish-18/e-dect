#ifndef __FUNSER_H__
#define __FUNSER_H__
#define PRINT(msg, res) \
    do                  \
    {                   \
        printf(msg);    \
        return res;     \
    } while (0)
#define PRINT_ERR(msg, res)             \
    do                                  \
    {                                   \
        printf("line = %d,", __LINE__); \
        perror(msg);                    \
        return res;                     \
    } while (0)
#define PRINT_SQL(msg, res)                                                \
    do                                                                     \
    {                                                                      \
        printf("line = %d,sql errmsg = %s", __LINE__, sqlite3_errmsg(db)); \
        return res;                                                        \
    } while (0)

sqlite3 *load_sql(char *path);
int bindaddr(int sfd,int port,char *ip);
int do_register(int newfd, char *username, sqlite3 *db);
int do_login();
#endif
