struct DateOfBirth
{
    int day;
    int month;
    int year;
};
typedef struct contact
{
    char FirstName [100];
    char LastName [100];
    struct DateOfBirth DOB;
    char address [100];
    char email [100];
    char phone [50] ;
} notebook;
void Load(notebook c1[]);
void Add(notebook c1[]);
void Delete(notebook c1[]);
void search_contacts(notebook c1[]);
void Sort(notebook c1[]);
void Modify(notebook c1[]);
void Save(notebook c1[]);
void Welcome();
