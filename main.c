#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Account
{
    int account_id;
    char name[100];
    float balane;
    char password[50];
};



int main()
{
    struct Account accounts[100];
    int numAccount = 0 ;
    int choice ;
    do
    {
        printf("============================================================\n");
        printf("Welcome to Ahmed & Hisham Bank \n");
        printf("============================================================\n");
        printf("1- Create Account \n");
        printf("2- Deposit \n");
        printf("3- withdraw \n");
        printf("4- account information \n");
        printf("5- Exit \n");
        printf("Enter your Choice : ");
        scanf("%d" , &choice);
    switch(choice)
    {
    case 1:
        createAccount(accounts ,&numAccount);
        break;
    case 2:
        Deposit(accounts ,numAccount);
        break;
    case 3:
        withdraw(accounts ,numAccount);
        break;
    case 4:
        accountInformation(accounts,numAccount);
        break;
    case 5:
        printf("Exiting .... \n");
        break;
    default :
        printf("invalid choice !!!!!!\n");
    }
    }
    while(choice != 5);
    return 0;
}

void createAccount(struct Account *accounts ,int *numAccount )
{
    fflush(stdin);
    printf("Enter your name : ");
    fgets(accounts[*numAccount].name, sizeof(accounts[*numAccount].name), stdin);
    fflush(stdin);
    printf("Enter your Password : ");
    fgets(accounts[*numAccount].password, sizeof(accounts[*numAccount].password), stdin);
    if(accounts[*numAccount].password == NULL)
    {
        printf("you Entered invalid password !!");
        return;
    }
    printf(" Password created !! \n");
    printf("Enter your initial balance : ");
    scanf("%f" ,&accounts[*numAccount].balane );
    accounts[*numAccount].account_id = *numAccount +1;
    printf("Account Created Successfully !! \nyour ID is : %d \n" , accounts[*numAccount].account_id);
    (*numAccount) += 1 ;
}

void Deposit(struct Account *accounts ,int numAccount )
{
    int accountNumber;
    float amount;
    printf("Enter your Id : ");
    scanf("%d" ,&accountNumber );
    if(accountNumber <= 0 || accountNumber > numAccount || accountNumber == NULL )
    {
        printf("you Entered invalid ID ): !! \n");
        return;
    }

    printf("welcome %s" , accounts[accountNumber - 1].name);
    printf("Enter your Amount : ");
    scanf("%f" , &amount);
    accounts[accountNumber - 1 ].balane += amount;
    printf("you deposit successfully !!\n");
    printf("your current balance is = %0.2f \n", accounts[accountNumber - 1].balane);

}

void withdraw(struct Account *accounts , int numAccount)
{
    int user_input_id ;
    char user_input_password[100];
    float amount ;
    printf("Now i will check if you a Bank robber :) \n");
    printf("Enter your ID : ");
    scanf("%d", &user_input_id );

    if(user_input_id == NULL || user_input_id > numAccount || user_input_id <= 0)
    {
        printf("Wrong ID !! ): !! \nI Got You Robber !!\n");
        return ;
    }

    fflush(stdin);
    printf("Enter Account password : ");
    fgets(user_input_password, sizeof(user_input_password), stdin);

    if (strcmp(user_input_password, accounts[user_input_id - 1 ].password) != 0)
    {
        printf("Access denied. Incorrect password!\nI Got You Robber !! :) \n");
        return;
    }

    printf("welcome %s " , accounts[user_input_id - 1].name);
    printf("Enter your withdraw amount : ");
    scanf("%f" , &amount);
    if(amount > accounts[user_input_id - 1 ].balane)
    {
        printf("you do not have enough money in your account !! \n");
        return;
    }
    printf("your amount is successfully withdraw !! \n");
    accounts[user_input_id - 1 ].balane -= amount;
    printf("your current money is : %0.2f  \n" ,accounts[user_input_id - 1 ].balane );
}

void accountInformation(struct Account *accounts, int numAccount){
        int user_inPut_id;
        char user_inPut_password[100];
        printf("Enter your ID :");
        scanf("%d",&user_inPut_id);
        if ((user_inPut_id == NULL) || (user_inPut_id  > numAccount ) || (user_inPut_id <=0 )){
           printf("Wrong ID !! ): !! \nI Got You Robber !!\n");
           return ;
        }

        fflush(stdin);
        printf("Pleas Enter your password :) ");
        fgets(user_inPut_password,sizeof(user_inPut_password),stdin);

        if(strcmp(user_inPut_password , accounts[user_inPut_id - 1].password)!=0)
        {
            printf("Access denied. Incorrect password!\nI Got You Robber !! :) \n");
            return;
        }
        else{
            printf("welcome :) %s",accounts[user_inPut_id - 1 ].name);
            printf("your amount is : %0.2f \n",accounts[user_inPut_id - 1 ].balane);
            printf("your ID : %d \n",accounts[user_inPut_id - 1 ].account_id);
            return;
        }
}
