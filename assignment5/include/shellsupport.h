
#ifndef SHELLSUPPORT_H

#define SHELLSUPPORT_H


/*Supporting functions*/
int parser(char* buf);
void setlocal(char* var_name,int name_count, char* var_val, int val_count);
void setprint(void);
int exportenv(void);
void assignvar(char* buf);
int echoparser(char* buf);

#endif /*SHELLSUPPORT_H*/
