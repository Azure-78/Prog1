struct Country {
  char name[16];
  int code;
  struct Country *next;
};

struct Vote {
  int number;
  char voter[16];
  char voted[16];
  int points;
  struct Vote *next;
};

int p_show(struct Country *list_c);
int p_new(struct Country **list_c);
int p_remove(struct Country **list_c);
int p_add(struct Vote **list_v, int *n_v);
int p_list(struct Vote *list_v);
int p_init(struct Country **list_c, struct Vote **list_v, int *n_v);
int p_end(struct Country *list_c, struct Vote *list_v);
