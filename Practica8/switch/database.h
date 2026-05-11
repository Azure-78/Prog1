
struct Country {
char name[16];
int code;
};

int p_show(struct Country *tab_c, int number);
int p_new();
int p_remove();
int p_add();
int p_list();
int p_init(struct Country *tab_c, int *number);

