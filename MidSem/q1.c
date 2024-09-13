/*
Write a C program of hospital structure with data members name,id,ailment and age of patients with the following conditions.
1. Dynamically Allocate memory for N patient’s data taking N inputs from the user and display information of all the patients 
2. Assume more patients rushed into the hospital then increase the dynamically allocated space for all the excess patients (Hint: use realloc)
3. A patient gets discharged, then display the number of remaining patients in the hospital and their corresponding data values
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char Name[30];
    int Id;
    int Age;
    char Ailment[20];
    int Available;
}Patient;

void display(Patient *item){
    printf("\n");
    printf("    Patient Name: %s \n",item->Name);
    printf("    Patient Id: %d \n",item->Id);
    printf("    Patient Age: %d \n",item->Age);
    printf("    Patient Ailment: %s \n",item->Ailment);
    printf("    Patient Available: %d \n",item->Available);
    printf("    -------------------------- \n");
}

void read(Patient *item){
    printf("    Enter Patient Name: ");
    scanf("%s",item->Name);
    printf("    Enter Patient Id: ");
    scanf("%d",&item->Id);
    printf("    Enter Patient Age: ");
    scanf("%d",&item->Age);
    printf("    Enter Patient Ailment: ");
    scanf("%s",item->Ailment);
    item->Available = 1;
}

void Mark_Discharged(Patient *item){
    item->Available = 0;
}

int main(){
    int Max_Patients,Curr_Patient;Curr_Patient = 0;
    printf("Enter Initial Number of Patients: ");
    scanf("%d",&Max_Patients);
    Patient *list = calloc(Max_Patients,sizeof(Patient));
    if(!list){
        printf("Unable to Allocate Memory!");
        exit(0);
    }
    printf("1. Add Patient 2. Display Patient 3. Mark Discharge 4. Exit \n");
    int option,id;
    while(1){
        printf("Enter Menu No: ");
        scanf("%d",&option);
        switch(option){
            case 1:
                if(Curr_Patient > Max_Patients - 1){
                    list = (Patient*) realloc(list,2*Max_Patients*sizeof(Patient));
                    Max_Patients = 2*Max_Patients;
                    printf("More Space Allocated! \n");
                }
                read(&list[Curr_Patient++]);
            break;
            case 2:
                printf("    Enter Patient Id:");
                scanf("%d",&id);
                for(int i = 0;i<Curr_Patient;i++){
                    if(list[i].Id == id){
                        display(&list[i]);
                        break;
                    }
                }
            break;
            case 3:
                printf("    Enter Patient Id:");
                scanf("%d",&id);
                for(int i = 0;i<Curr_Patient;i++){
                    if(list[i].Id == id){
                        Mark_Discharged(&list[i]);
                        break;
                    }
                }
                int count = 0;
                for(int i = 0;i<Curr_Patient;i++){
                    if(list[i].Available == 1){
                        display(&list[i]);
                        count++;
                    }
                }
                printf("    Total Avaialble Patients : %d \n",count);
            break;
            case 4:
                free(list);
                exit(0);
            break;
            default:
                printf("Enter Appropriate Menu No! \n");
        }
    }
}