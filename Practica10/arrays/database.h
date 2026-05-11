
struct Country {
char name[16];
int code;
};

struct Vote {
    int number;
    char voter[16];
    char voted[16];
    int points;
};

int p_show(struct Country *tab_c, int *n_c);
int p_new(struct Country *tab_c, int *n_c);
int p_remove();
int p_add(struct Vote *tab_v, int *n_v);
int p_list(struct Vote *tab_v, int n_v);
int p_init(struct Country *tab_c, int *n_c, struct Vote *tab_v ,int *n_v);
int p_end(struct Country *countries, int numCountries, struct Vote *votes, int numVotes);

