#include <stdio.h>
#include <string.h>


struct Contact
{
    char nom[40];
    int num;
    char email[40];

};
int count = 0;


struct Contact emp[5]; 

int chercher(char a[40]){

    for(int i=0 ; i<count ; i++){
        char nom[40] ;

        strcpy(nom, emp[i].nom);

        

        if( strcmp(nom,a)==0)
        {

            printf("%d" , i);
           return i;
        }
        
    }

    return -1;

}


void insert(){
    struct Contact c;
            printf("Entrer le nom: ");
            scanf("%s", c.nom);

            printf("Entrer le numero tele  ");
            scanf("%d", &c.num);

            printf("Entrer l'email: ");
            scanf("%s", c.email);

             emp[count]=c;

            count++;
           



}
void modifier(){
    char x[40];

   printf("enter le nom de contact ");
   scanf("%s" , x);
     int y=chercher(x);
     if(y==-1){
        printf(" le contact n'exist pas");
     }else{

        char e[30];
        printf("enter un nouveau adersse  email");
        scanf("%s" , e);
        int n;
        printf("enter un nouveau numéro");
        scanf("%d" , &n);


        strcpy(emp[y].email,e);

         emp[y].num=n;

        printf("les infrmation a ete modifier");

     }

}
void supprimer(){
     char x[40];

   printf("enter le nom de contact ");
   scanf("%s" , x);

    int res = chercher(x);
    printf("%d" , res);

    if (res==-1)
    {
        printf("ce contact n'exist pas");
    }else{
        for (int i = res; i < count-1; i++)
        {
           emp[i]=emp[i+1];
        }
        count--;
        
    }
    
     

}



void affiche(){


    if(count>0){
        for (int i = 0; i < count; i++)
        {
           printf("nom: %s,num : %d , email: %s, \n",
                    emp[i].nom, emp[i].num, emp[i].email);

        }
        




    }
}

void chercherContact(){
    char nom[40];

   printf("enter le nom de contact ");
   scanf("%s" , nom);

   int res =chercher(nom);

    if (res==-1)
    {
        printf("ce contact n'exist pas");
    }else{
        
         printf("le nom : %s , le num : %d , l'email : %s", emp[res].nom ,emp[res].num ,emp[res].email );
        
        
    }



}



int main(){
int state=0;
while (state!=9)
{
        printf("Si vous voulez ajouter un contact, entrez [1]\n");
        printf("Si vous voulez afficher les contactes, entrez [2]\n");
        printf("Si vous voulez rechercher un contact, entrez [3]\n");
        printf("Si vous voulez mettre à jour un contact, entrez [4]\n");
        printf("Si vous voulez supprimer un contact, entrez [5]\n");
        
        printf("Pour quitter, entrez [9]\n");

       scanf("%d",&state);


       switch (state)
       {
       case 1:
         insert();
        break;
       case 2:
         affiche();
        break;
        case 3:

        
         chercherContact();
        break;
        case 4:
         modifier();
        break;
        case 5:

         supprimer();
        break;
       default:
        break;
       }




}



}