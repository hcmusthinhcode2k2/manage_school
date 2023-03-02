#include <stdio.h>
#include <string.h>

#define  MAX_STUDENTS 100
#define  MAX_CLASSES  100

typedef  struct Student {
    char name[50];
    float grade;
}Student;
typedef  struct Class {
    char name[50];
    int size;
    Student students[MAX_STUDENTS];
}Class;
void nhaplop(Class classes[],int *num_classes)
{
    Class new_class;
    printf("nhap vao ten lop:");
    scanf("%s",new_class.name);
    printf("nhap vao si so lop:");
    scanf("%d",&new_class.size);
    printf("nhap vao thong tin sinh vien:\n");
    for (int i=0;i<new_class.size;i++)
    {
        printf("Student %d name: ", i+1);
        scanf("%s", new_class.students[i].name);
        printf("Student %d grade: ", i+1);
        scanf("%f", &new_class.students[i].grade);
    }
    classes[*num_classes]=new_class;
    (*num_classes)++;
}
void lopcotren5svgioi(Class c)
{
    int count=0;
    for (int i=0;i<c.size;i++)
    {
        if (c.students[i].grade>=8)
        {
            count++;
        }
    }
    if (c.size>5 && count>5)
    {
        printf("%s\n", c.name);
    }
}
void lopnhieusinhviennhat(Class classes[], int num_classes) {
    int max_size = 0;
    int max_index = -1;
    for (int i = 0; i < num_classes; i++) {
        if (classes[i].size > max_size || (classes[i].size == max_size && i < max_index)) {
            max_size = classes[i].size;
            max_index = i;
        }
    }
    printf("lop co nhieu sinh vien nhat: %s (%d students)\n", classes[max_index].name, classes[max_index].size);
}

void lopitsinhviennhat(Class classes[], int num_classes) {
    int min_size = MAX_STUDENTS + 1;
    int min_index = -1;
    for (int i = 0; i < num_classes; i++) {
        if (classes[i].size < min_size || (classes[i].size == min_size && i < min_index)) {
            min_size = classes[i].size;
            min_index = i;
        }
    }
    printf("lop co it sinh vien nhat: %s (%d students)\n", classes[min_index].name, classes[min_index].size);
}

void timsinhviengioi(Class classes[], int num_classes)
{
    char top_students[50][50];
    float top_grade = 0;
    int num_top_students = 0;

    for (int i = 0; i < num_classes; i++)
    {
        for (int j = 0; j < classes[i].size; j++)
        {
            if (classes[i].students[j].grade > top_grade)
            {
                num_top_students = 1;
                top_grade = classes[i].students[j].grade;
                strcpy(top_students[0], classes[i].students[j].name);
            }
            else if (classes[i].students[j].grade == top_grade)
            {
                strcpy(top_students[num_top_students], classes[i].students[j].name);
                num_top_students++;
            }
        }
    }

    printf("Sinh vien co diem trung binh cao nhat (%.2f):\n", top_grade);
    for (int i = 0; i < num_top_students; i++)
    {
        printf("- %s\n", top_students[i]);
    }
}

void timlopconhieusinhviengionhat(Class classes[],int num_classes)
{
    int max_good_students=0;
    int max_index=-1;
    for (int i=0;i<num_classes;i++)
        {
           int count=0;
           for (int j=0;j<classes[i].size;j++)
           {
               if (classes[i].students[j].grade>=8)
               {
                   count++;
               }
           }
           if (count>max_good_students)
           {
               max_good_students=count;
               max_index=i;
           }
        }
    printf("Lop co nhieu hoc sinh gioi nhat: %s (%d students)\n",classes[max_index].name,max_good_students);
}
int main()
{
    Class  classes[MAX_CLASSES];
    int num_classes;
    int choice;
    do {
        printf("\n1.Nhap lop\n");
        printf("2.In ra danh sach lop co tren 5 sinh vien co diem trung binh loai gioi\n");
        printf("3.Lop co nhieu sinh vien nhat\n");
        printf("4.Lop co it sinh vien nhat\n");
        printf("5.Sinh vien co diem trung binh cao nhat\n");
        printf("6.Lop co nhieu hoc sinh gioi nhat\n");
        printf("0.Thoat\n");
        scanf("%d",&choice);
    switch (choice) {
        case 1:
            nhaplop(classes,&num_classes);
            break;
        case 2:
            printf("In ra danh sach lop co tren 5 sinh vien co diem trung binh loai gioi:\n");
            for (int i=0;i<num_classes;i++)
            {
                lopcotren5svgioi(classes[i]);
            }
            break;
        case 3:
            lopnhieusinhviennhat(classes,num_classes);
            break;
        case 4:
            lopitsinhviennhat(classes,num_classes);
            break;
        case 5:
            timsinhviengioi(classes,num_classes);
            break;
        case 6:
            timlopconhieusinhviengionhat(classes,num_classes);
            break;
        case 0:
            printf("Tam biet!\n");
            break;
        default:
            printf("Lua chon khong hop le!\n");
    }
    }while(choice!=0);
    return 0;
}