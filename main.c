#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

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
        printf("\t\t\t============================================================\n");
        printf("\t\t\t\t      Welcome to Ahmed & Hisham Bank \n");
        printf("\t\t\t============================================================\n");
        printf("\t\t\t1- Create Account \n");
        printf("\t\t\t2- Deposit \n");
        printf("\t\t\t3- Withdraw \n");
        printf("\t\t\t4- Edit Account Details \n");
        printf("\t\t\t5- Money Transfer To Another Account \n");
        printf("\t\t\t6- Exit \n");
        printf("\t\t\t============================================================\n");
        printf("\t\t\tEnter your Choice : ");
        scanf("%d" , &choice);
        printf("\t\t\t============================================================\n");
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
        editAccountDetails(accounts,numAccount);
        break;
    case 5:
        TransferMoney(accounts , numAccount);
    case 6:
        printf("\t\t\tExiting .... \n");
        break;
    default :
        printf("\t\t\tinvalid choice !!!!!!\n");
    }
    }
    while(choice != 6);
    return 0;
}

void createAccount(struct Account *accounts ,int *numAccount )
{
    printf("\t\t\t\t\t     Create Account \n");
    printf("\t\t\t============================================================\n");
    fflush(stdin);
    printf("\t\t\tEnter your name : ");
    fgets(accounts[*numAccount].name, sizeof(accounts[*numAccount].name), stdin);
    fflush(stdin);
    printf("\t\t\tEnter your Password : ");
    fgets(accounts[*numAccount].password, sizeof(accounts[*numAccount].password), stdin);
    if(accounts[*numAccount].password == NULL || strlen(accounts[*numAccount].password) <= 1 )
    {
        printf("\t\t\t============================================================\n");
        printf("\t\t\tyou Entered invalid password !! \nTry Again :( \n");
        return;
    }
    printf("\t\t\twait for creating your account ....\n");
    sleep(1.5);
    printf("\t\t\tAccount created !! \n");
    printf("\t\t\tEnter your initial balance : ");
    scanf("%f" ,&accounts[*numAccount].balane );
    accounts[*numAccount].account_id = *numAccount +1;
    printf("\t\t\tAdding your money ");
    for(int x = 0 ; x <4 ; x++)
    {
        printf(".");
        sleep(1);
    }
    printf(".\n");
    printf("\t\t\t============================================================\n");
    printf("\t\t\tAccount Created Successfully :) Thank you For using A&H Bank \n\t\t\tyour ID is : %d\n\t\t\tyour balance is : %0.2f EGP\n" , accounts[*numAccount].account_id , accounts[*numAccount].balane);
    printf("\t\t\tDo not Forget Your Password !! \n");
    (*numAccount) += 1 ;
    sleep(2);
}

void Deposit(struct Account *accounts ,int numAccount )
{
    printf("\t\t\t\t\t\t Deposit \n");
    printf("\t\t\t============================================================\n");
    int accountNumber;
    float amount;
    char user_password[100];
    printf("\t\t\tEnter your Id : ");
    scanf("%d" ,&accountNumber );
    printf("\t\t\tEnter your Password : ");
    fflush(stdin);
    fgets(user_password,sizeof(user_password),stdin);
    if(accountNumber <= 0 || accountNumber > numAccount || accountNumber == NULL|| strcmp(user_password,accounts[accountNumber -1].password)!=0 )
    {
        printf("\t\t\tyou Entered Invalid Data ): !! \n");
        return;
    }

    printf("\t\t\t\t\t welcome %s" , accounts[accountNumber - 1].name);
    printf("\t\t\tEnter your Amount : ");
    scanf("%f" , &amount);
    accounts[accountNumber - 1 ].balane += amount;

    printf("\t\t\tAdding your Money ....\n");
    sleep(1);
    printf("\t\t\tyour money deposited successfully :) \n");
    printf("\t\t\tyour current balance is = %0.2f EGP \n", accounts[accountNumber - 1].balane);
    sleep(2);
}

void withdraw(struct Account *accounts , int numAccount)
{
    int user_input_id ;
    char user_input_password[100];
    float amount ;
    printf("\t\t\t\t\t\t Withdraw \n");
    printf("\t\t\t\tNow i will check if you a Bank robber :) \n");
    printf("\t\t\t============================================================\n");
    printf("\t\t\tEnter your ID : ");
    scanf("%d", &user_input_id );

    if(user_input_id == NULL || user_input_id > numAccount || user_input_id <= 0)
    {
        printf("\t\t\tWrong ID !! ): !! \n\t\t\tI Got You Robber !!\n");
        return ;
    }

    fflush(stdin);
    printf("\t\t\tEnter Account password : ");
    fgets(user_input_password, sizeof(user_input_password), stdin);

    if (strcmp(user_input_password, accounts[user_input_id - 1 ].password) != 0)
    {
        printf("\t\t\tAccess denied. Incorrect password!\n\t\t\tI Got You Robber !! :) \n");
        return;
    }

    printf("\t\t\t\t\t     welcome %s" , accounts[user_input_id - 1].name);
    printf("\t\t\tEnter your withdraw amount : ");
    scanf("%f" , &amount);
    printf("\t\t\tPlease wait");
    for(int i = 0 ; i < 4 ; i++ )
    {
        printf(".");
        sleep(1);
    }
    printf("\n");
    if(amount > accounts[user_input_id - 1 ].balane)
    {
        printf("\t\t\tyou do not have enough money in your account !! \n");
        return;
    }
    printf("\t\t\tyour amount is successfully withdraw !! \n");
    accounts[user_input_id - 1 ].balane -= amount;
    printf("\t\t\tyour current money is : %0.2f EGP \n" ,accounts[user_input_id - 1 ].balane );
    printf("\t\t\tExiting To The Main List ");
    for(int i = 0 ; i < 4 ; i++)
    {
        printf(".");
        sleep(1);
    }
    printf("\n");
}

void editAccountDetails(struct Account *accounts, int numAccount){
        int user_inPut_id;
        char user_edit_password[100];
        int choice;
        char user_inPut_password[100];
        printf("\t\t\tEnter your ID : ");
        scanf("%d",&user_inPut_id);
        if ((user_inPut_id == NULL) || (user_inPut_id  > numAccount ) || (user_inPut_id <=0 )){
           printf("\t\t\tWrong ID !! ): \n\t\t\tI Got You Robber !!\n");
           return ;
        }

        fflush(stdin);
        printf("\t\t\tEnter your password : ");
        fgets(user_inPut_password,sizeof(user_inPut_password),stdin);
        if(strcmp(user_inPut_password , accounts[user_inPut_id - 1].password)!=0)
        {
            printf("\t\t\tAccess denied. Incorrect password!\n\t\t\tI Got You Robber !! :) \n");
            return;
        }
            printf("\t\t\twelcome :) %s",accounts[user_inPut_id - 1 ].name);
            printf("\t\t\tyour Money is : %0.2f EGP \n",accounts[user_inPut_id - 1 ].balane);
            printf("\t\t\tyour ID : %d \n",accounts[user_inPut_id - 1 ].account_id);
            do
                {
                    printf("\t\t\t==============================================\n");
                    printf("\t\t\t1- edit user name \n");
                    printf("\t\t\t2- edit password \n");
                    printf("\t\t\t3- main list \n");
                    printf("\t\t\tenter your choice : ");
                    scanf("%d" , &choice);
                    switch(choice)
                        {
                            case 1:
                                fflush(stdin);
                                printf("\t\t\tEnter your New user Name : ");
                                fgets(accounts[user_inPut_id - 1 ].name , sizeof(accounts[user_inPut_id - 1 ].name), stdin);
                                printf("\t\t\tuser name Changed Correctly !!\n");
                                break;
                            case 2:
                                fflush(stdin);
                                printf("\t\t\tenter your new password : ");
                                fgets(accounts[user_inPut_id - 1 ].password , sizeof(accounts[user_inPut_id - 1 ].password) , stdin);
                                printf("\t\t\tpassword Changed correctly !! \n");
                                break;
                            case 3:
                                printf("\t\t\tExiting....\n");
                                sleep(3);
                                break;

                            default :
                                printf("\t\t\tyou Entered invalid choice !!\n");
                                return;
                            }}while(choice != 3);
}

void TransferMoney(struct Account *accounts, int numAccount)
{
    int senderID , ReceiverID;
    float amount_to_transfer , sender_Total_money ;
    char sender_password[100];
    printf("\t\t\tTransfer Money \n");
    printf("\t\t\t==============================================\n");
    printf("\t\t\tEnter Your ID : ");
    scanf("%d" , &senderID);
    printf("\t\t\tEnter Your Password : ");
    fflush(stdin);
    fgets(sender_password , sizeof(sender_password) , stdin);
    if(strcmp(sender_password , accounts[senderID - 1].password) != 0 || senderID != accounts[senderID - 1].account_id)
    {
        printf("\t\t\t==============================================\n");
        printf("\t\t\tInvalid Data !! \n");
        return;
    }
    printf("\t\t\tEnter Receiver ID : ");
    scanf("%d" , &ReceiverID);
    if(ReceiverID > numAccount || ReceiverID == NULL || ReceiverID <= 0)
    {
        printf("\t\t\t==============================================\n");
        printf("\t\t\tInvalid ID !! \n");
        return ;
    }
    printf("\t\t\tEnter Transfer Amount : ");
    scanf("%f" , &amount_to_transfer);
    if(amount_to_transfer > accounts[senderID - 1].balane)
    {
        printf("\t\t\t==============================================\n");
        printf("\t\t\tyou do not have Enough Money !!\n\t\t\tPlease recharge :) \n");
        return ;
    }
    accounts[senderID - 1 ].balane -=amount_to_transfer ;
    accounts[ReceiverID - 1 ].balane += amount_to_transfer;
    printf("\t\t\t==============================================\n");
    printf("\t\t\tPlease Wait\n");
    for( int i=0; i < 4 ; i++)
        {
            printf(".");
            sleep(1);
        }
        printf("\t\t\tYour Money transfered successfully :) \n");
        printf("\t\t\tYour Amount is %0.2f \n",accounts[senderID -1].balane);
        sleep(2);
}






