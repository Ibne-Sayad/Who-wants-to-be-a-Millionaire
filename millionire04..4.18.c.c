#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <time.h>
#include <windows.h>
#include <conio.h>
#include <ctype.h>


void rules();
void registration();
void play();


struct user
{
    char name[50];
    int age[50];
    char NID[50];
    char AC[50];
    char PW[50];
    char CPW[50];

    char name3 [50];
    char name2[50];
    int score;
    int score2;
    int ac2;
} reg;
////////////////////////////Admin panel////////////////

admin()
{
    int i;
    printf("\n\n\n\n\n\n");
    printf("                                                               >>Enter <1> for Display score.\n");
    printf("                                                               >>Enter <2> for Modify a score.");

    printf("\n\n\n                                                         >>Enter your option: ");
    scanf("%d",&i);

    if(i==1)
    display_all();
    else
        modify_score();
        main();
}



struct login{

    char fname[100];
    char lname[20];
    char username[20];
    char password[20];
    };

registe()
{
    FILE *log;
    log=fopen("login12.txt","w");
    struct login l;
    printf("\n\n\n\n");
    printf("                                                           \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
    printf("                                                           \xB2\xB2 Admin Registration\xB2\xB2\n");
    printf("                                                           \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n\n");
    printf("                                        >>Enter first name: ");scanf("%s",l.fname);

    printf("                                        >>Enter last name: ");scanf("%s",l.lname);

    printf("                                        >>Enter Username : ");scanf("%s",l.username);
    printf("                                        >>Enter password : ");scanf("%s",l.password);
    fwrite(&l,sizeof(l),1,log);

    fclose(log);

    printf("\n\n                                        >>Your User name is UserID.\n");
    printf("                                        >>Now login with UserID and Password.\n");
    printf("\n\n\n\n            Press <Enter> to continue......");
    getch();
    system("CLS");
    adlogin();

}

adlogin()
{

    char username[200],password[20];
    FILE *log;
    log=fopen("login12.txt","r");
    struct login l;
    printf("\n\n\n\n");
    printf("                                                           \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
    printf("                                                           \xB2\xB2 Admin Login  \xB2\xB2\n");
    printf("                                                           \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n\n\n\n");

    printf("                                                            >>UserID: ");
    scanf("%s",&username);
    printf("                                                            >>Password: ");
    scanf("%s",&password);

    while(fread(&l,sizeof(l),1,log))
        {
           if(strcmp(username,l.username)==0 && strcmp(password,l.password)==0)
           {
               printf("\n\n\n                                                           !!!Login successful!!!\n\n\n");
               Sleep(3500);
               system("cls");
               admin();
           }
           else {
            printf("\n\n\n                                                  >>Please Enter correct UserID and Password\n\n");

            Sleep(3500);
            system("cls");

            adlogin();
            break;
           }
        }

    fclose(log);
}


FILE *f;




 modify_score()
{
    int no,found=0,num;
    system("cls");
    printf("\n\n\n\n");
    printf("                                                           \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
    printf("                                                           \xB2\xB2 Modify score  \xB2\xB2\n");
    printf("                                                           \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n\n\n\n");
    printf("\n\n\t                                                   >>Please Enter The A/C no.: ");
    scanf("%d",&no);
    f=fopen("scorec.txt","rb+");
     while((fread(&reg,sizeof(reg),1,f))>0 && found==0)
    {
    if(reg.ac2==no)
           {
            fflush(stdin);
            printf("\n                                                     >>Player name : %s",reg.name2);
            printf("\n                                                     >>Wining money : %d",reg.score);
            printf("\n                                                     >>A/C no : %d",reg.ac2);
            printf("\n\n\n\n                                               >>Please Enter The New Details of player \n\n");



            printf("\n                                                   >>Enter the name of the player: ");
            fflush(stdin);
            scanf("%d",&reg.name2);
             fflush(stdin);
            printf("                                                     >>Update wining money: ");
            scanf("%d",&reg.score2);
             fflush(stdin);
            printf("                                                     >>Update The A/C no.: ");
            scanf("%d",&reg.ac2);



            fseek(f,-(long)sizeof(reg),1);
            fwrite(&reg,sizeof(reg),1,f);system("cls");
            printf("\n\n\t                                               >>Record Updated!!");
            found=1;

            printf("\n\n\n\n                                              Press <M> for main menu:\n");
            scanf("%s",&num);
            system("cls");
            main();

            //system("cls");
           }
           else
            printf("\n\n                                                      >>Record not found");

            printf("\n\n\n\n                                              Press <M> for main menu:\n");
            scanf("%s",&num);
            system("cls");
            main();
            Sleep(3500);
            system("cls");
         }
    fclose(f);

    getch();
}


void error()
{
    MessageBox(0,"Wrong key! Enter the correct one/n","error!",0);
}






/////////////////////////////*****home****//////////////////////////////

main()
{
    int i;
    printf("\n\n\n");
    printf("                                        \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2                                                     \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
    printf("                                        \xB2\xB2                                                                       \xB2\xB2\n");
    printf("                                        \xB2\xB2            \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2            \xB2\xB2\n");
    printf("                                        \xB2\xB2            \xB2\xB2  Welcome to Who Wants to be a Millionaire!\xB2\xB2            \xB2\xB2\n");
    printf("                                        \xB2\xB2            \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2            \xB2\xB2\n");


    printf("                                                       *Let's meet with some functions for this GAME*\n\n\n");

    int choose;
    {

        printf("                                                     >>1.Rules and regulations.\n");
        printf("                                                     >>2.Registration.\n");
        printf("                                                     >>3.login\n");
        printf("                                        \xB2\xB2           >>4.Play game.                                              \xB2\xB2\n");
        printf("                                        \xB2\xB2           >>5.View score.                                             \xB2\xB2\n");
        printf("                                        \xB2\xB2           >>6.Admin panel.                                            \xB2\xB2\n");
        printf("                                        \xB2\xB2                                                                       \xB2\xB2\n");printf("                                        \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2                                                     \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");


        printf("\n                                                           Choose any one option:");
        scanf("%d",&choose);


    }

    switch(choose)
    {
    case 1:

        system("CLS");
        rules();
        break;

    case 2:
    {
        system("CLS");
        registration();
        break;
    }
    case 3:
    {
        system("CLS");
        login();
        break;
    }
    case 4:
    {
        system("CLS");
        play();
        break;
    }
    case 5:
    {
        system("CLS");
        display_all();
        break;
    }
    case 6:
    {
        system("CLS");
        printf("\n\n\n\n");
        printf("                                        \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2                                            \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
        printf("                                        \xB2\xB2                                                              \xB2\xB2\n");
        printf("                                                                \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
        printf("                                                                \xB2\xB2 Admin panel \xB2\xB2\n");
        printf("                                                                \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n\n");


        printf("\n\t\t\t                                       >>1.Registration\n");
        printf("\n\t\t\t                                       >>2.Login");
        int x;
        printf("\n\n\n\n\n\n\t\t\t                                       Enter your option: ");

        scanf("%d",&x);
        system("cls");
        if(x==1) registe();
        else adlogin();
        break;
    }


    }
}
//////////////////////*****home end****//////////////////////////////









//////////////////////////////****rules****//////////////////////////

void rules()
//system("CLS");
{
    char enter,num;
    printf("\n\n");
    printf("\t\t\t\t            \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
    printf("\t\t\t\t            \xB2\xB2 Rules & Regulations\xB2\xB2\n");
    printf("\t\t\t\t            \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
    printf("\n      >>1.It's a game and by it you can be a millionaire by facing some questions.\n");
    printf("\n      >>2.You have to face total 12 questions.\n");

    printf("\n\t              >>(i) 1st question will carry 100 Tk\n");
    printf("\t              >>(ii) 2nd question will carry 500 Tk\n");
    printf("\t              >>(iii) 3rd question will carry 1,000 Tk\n");
    printf("\t              >>(iv) 4th question will carry 2,000 Tk\n");
    printf("\t              >>(v) 5th question will carry 4,000 Tk\n");
    printf("\t              >>(vi) 6th question will carry 10,000 Tk\n");
    printf("\t              >>(vii) 7th question will carry 20,000 Tk\n");
    printf("\t              >>(viii) 8th question will carry 30,000 Tk\n");
    printf("\t              >>(ix) 9th question will carry 50,000 Tk\n");
    printf("\t              >>(x) 10th question will carry 70,000 Tk\n");
    printf("\t              >>(xi) 11th question will carry 1,00,000 Tk\n");
    printf("\t              >>(xii) 12th question will carry 10,00,000 Tk\n");
    printf("\n      >>3. There will be total 3 life lines and also 3 safe zone.\n");

    printf("\n\t              >>(i)50:50\n");
    printf("\t              >>(ii)Phone a friend \n");
    printf("\t              >>(iii)Audience poll\n");

    printf("\n      >>4.For each question  there is a time limit\n");
    printf("\t              >>1st 3 question will carry 50sec \n");
    printf("\t              >>2nd 3 question will carry 40sec \n");
    printf("\t              >>3rd 3 question will carry 30sec \n");
    printf("\t              >>4th 3 question will carry 25sec \n");

    printf("\n      >>6.If you quit game at any stage you will get the earlier safe zone's money.\n");

    printf("\n      >>7.Finally for play this game you haveto go through a registration process by submitting your Name, Age, A/C no. ,NID no. \n\n\n\n");
    printf("    Press <M> for main menu:\n");
    scanf("%s",&num);
    system("cls");
    main();



}

//////////////////////////////****rules end****//////////////////////////



///////////////////////////////*****registration*****/////////////////////

void registration()
{
    int num;
    struct user reg;
    FILE *ptr;

    printf("\n\n\n\n");
    printf("                                        \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2                        \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
    printf("                                        \xB2\xB2                                          \xB2\xB2\n");
    printf("                                        \xB2\xB2            \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2            \xB2\xB2\n");
    printf("                                        \xB2\xB2            \xB2\xB2 Registretion:\xB2\xB2            \xB2\xB2\n");
    printf("                                        \xB2\xB2            \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2            \xB2\xB2\n\n\n\n");

    ptr=fopen("player.txt", "a");

    printf("                                              >> Enter your Name: ");
    scanf("%s",&reg.name);
    printf("                                              >> Enter your Age: ");
    scanf("%d",&reg.age);
    printf("                                              >> Enter your NID: ");
    scanf("%s",&reg.NID);
    printf("                                              >> Enter your A/C no.: ");
    scanf("%d",&reg.AC);
    fflush(stdin);
    printf("                                              >> Create password: ");
    scanf("%s",&reg.PW);
    printf("                                              >> Confirm password: ");
    scanf("%s",&reg.CPW);

    fwrite(&reg,sizeof(reg),1,ptr);
    fclose(ptr);
    printf("\n\n\n                                       >>Your registration has been successful!");
    printf("\n\n\n      >>Press <M> for main menu:\n");
    scanf("%s",&num);

    system("cls");
    login();


}

///////////////////////////////*****registration end*****///////////////////////////

///////////////////////////////*****Login*****///////////////////////////

login()
{
    char uname[15],upass[15];
    int x=0,s;
    FILE *ptr;

    do
    {
        system("cls");
        printf("\n\n\n\n");
        printf("                                           \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2                        \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
        printf("                                           \xB2\xB2                                          \xB2\xB2\n");
        printf("                                           \xB2\xB2               \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2               \xB2\xB2");
        printf("\n\t\t\t                                    \xB2\xB2Sign In \xB2\xB2\n");
        printf("                                                            \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
        ptr=fopen("player.txt","r");
        printf("\n\n\n                                                       >>Enter your UserName: ");
        scanf("%s",&uname);
        printf("\n                                                       >>Enter your Password: ");
        scanf("%s",&upass);
        while(fread(&reg,sizeof(reg),1,ptr))
        {
            if(strcmp(uname,reg.name)==0 && strcmp(upass,reg.PW)==0)
            {
                printf("\n\n\n\n                                                       !!!Signin successful!!!\n");

                x=1;
                printf("\n\n\n      Press <Enter> for continue the game!\n");
                if(getch()==13)

                    system("CLS");

                play();    ///**************************
            }
        }
        if(strcmp(uname,reg.name)!=0 && strcmp(upass,reg.PW)!=0)
        {

            printf("\n\n                                                          !!!!Signin failed!!!");
            Sleep(3000);
            printf("\n\n\n      Press <Enter> to try again!\n");

            x=0;


            login();

            break;
              //system("CLS");
        }
    }
    while(x==0);


    fclose(ptr);

}
///////////////////////////////*****Login end*****///////////////////////////

///////////////////////////////*****Count down*****///////////////////////////

timelmt()
{


    unsigned int x_hours=0;
    unsigned int x_minutes=0;
    unsigned int x_seconds=0;
    unsigned int x_milliseconds=0;
    unsigned int totaltime=0,count_down_time_in_secs=0,time_left=0;


    clock_t x_startTime,x_countTime;
    count_down_time_in_secs=5;  // 1 minute is 60, 1 hour is 3600


    x_startTime=clock();  // start clock
    time_left=count_down_time_in_secs-x_seconds;   // update timer

    while (time_left>0)
    {
        x_countTime=clock(); // update timer difference
        x_milliseconds=x_countTime-x_startTime;
        x_seconds=(x_milliseconds/(CLOCKS_PER_SEC))-(x_minutes*60);
        x_minutes=(x_milliseconds/(CLOCKS_PER_SEC))/60;
        x_hours=x_minutes/60;

        time_left=count_down_time_in_secs-x_seconds; // subtract to get difference

        printf( "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n                                             >>Your game will start is just <%d> seconds ",time_left,count_down_time_in_secs);
        system ("CLS");

    }
    //printf( "\nYour game will start is just %d seconds ( %d )",time_left,count_down_time_in_secs);



    printf( "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n                                             >>Let's start the game\n\n\n");
    Sleep(2000);
    system("cls");
}

///////////////////////////////*****Countdown end*****///////////////////////////



/////////////////////////////////*****play game*****///////////////////////////////////////
void play()
{
    FILE *ptr;
    system("color 0a");
    int q1,q2,q3,q4,q5,q6,q7,q8,q9,q10,q11,q12,life1,lifechoose1,mnum,lifechoose2,life2,mnum2,lifechoose3,life3,mnum3,life4,lifechoose4,mnum4,life5,lifechoose5,mnum5;
    int life6,lifechoose6,mnum6,life7,lifechoose7,mnum7,life8,lifechoose8,mnum8,life9,lifechoose9,mnum9,life10,lifechoose10,mnum10,life11,lifechoose11,mnum11,life12,lifechoose12,mnum12;
    int countr=0;
    time_t time1,time2;
    double t;
    int c=0;
    int s=0;

    timelmt();

    //printf("\n                                                               Let's start the game\n\n\n");

    printf("\n\n1.Who is the fouder of Daffodil International university?\n");
    printf("1.Dr.Md.Yousuf Mahbubul Islam");
    printf("\t2.Md.Sobur Khan");
    printf("\t3.Dr.Touhid Bhuiyan");
    printf("\t4.Md.Abdul Hamid\n");
    time(&time1);

    printf("\n>>1.Lifelines!");
    printf("\n>>2.Direct answer!\n    =");
    scanf("%d",&lifechoose1);

    switch(lifechoose1)

    {
    case 1:
    {
        ///////////////////////////linelines//////////////////////////
        printf("\n  Choose a lifeline!\n");

        printf("    1. 50:50\n");
        printf("    2. Phone a Friend \n");
        printf("    3. Audience poll \n     =");
        scanf("%d",&life1);

        if (life1==1)
        {
            printf("\n\n1.Who is the fouder of Daffodil International university?\n");
            printf("1.Dr.Md.Yousuf Mahbubul Islam");
            printf("\t2.Md.Sobur Khan");
        }
        else if(life1==2)
        {
            printf("\n\n    >>Your friend is confused between option 2 and  3\n");
        }
        else
        {
            printf("\n\n1.Who is the fouder of Daffodil International university?\n");
            printf("1.Dr.Md.Yousuf Mahbubul Islam (Vote:30%%)");
            printf("\t2.Md.Sobur Khan (Vote:40%%)");
            printf("\t3.Dr.Touhid Bhuiyan (Vote:20%%)");
            printf("\t4.Md.Abdul Hamid (Vote:10%%)\n");
        }

    }
    ///////////////////////////end life lines////////////////////
    case 2:
    {


        printf("\n\n    Your ans:");




        scanf("%d",&q1);
        time(&time2);
        t=difftime(time2,time1);
        printf("\n\n    >>Your answering time is %0.2lf\n",t);
        if(t>50)
        {
            printf("                                                        !!! Timed out !!!\n");
            c=c+1;

            printf("\n  >>Press <M> for main menu:\n");
            scanf("%s",&mnum3);
            system("cls");
            main();
        }





        if(q1==2)

        {
            printf("\n    >>Your ans is correct!\n\n");

            s=s+100;

            printf("\n\t\t\t>>Now your wining money is %d TK!",s);
            Sleep(3000);
            system("CLS");


        }
        else

        {
            printf("Your ans is incorrect\n");
            reg.score=s;
            printf("\n\n\n  Your wining money is %d",reg.score);


            ptr=fopen("score.txt", "a");

            fwrite(&reg,sizeof(reg),1,ptr);
            fclose(ptr);

            write_name();
            printf("\nPress <M> for main menu:\n");
            scanf("%s",&mnum3);
            system("cls");
            main();
        }


    }

    }

    printf("\n\n2.Which one is the binary number?\n");
    printf("1.00001");
    printf("\t2.2112");
    printf("\t3.0421");
    printf("\t4.2A9B\n");

    time(&time1);

    printf("\n  >>1.Lifelines!");
    printf("\n  >>2.Direct answer!\n=");

    scanf("%d",&lifechoose2);

    switch(lifechoose2)

    {
    case 1:
    {
        ///////////////////////////linelines//////////////////////////
        printf("\nChoose a lifeline!\n");

        printf("1. 50:50\n");
        printf("2. Phone a Friend \n");
        printf("3. Audience poll \n");
        scanf("%d",&life2);

        if (life2==1)
        {
            printf("\n\n2.Which one is the binary number?\n");
            printf("1.00001");
            printf("\t2.2112");
        }
        else if(life2==2)
        {
            printf("\n\nYour friend is confused between option 1 and  3\n");
        }
        else
        {
            printf("\n\n2.Which one is the binary number?\n");
            printf("1.00001 (Vote30%%)");
            printf("\t2.2112 (Vote30%%)");
            printf("\t3.0421 (Vote25%%)");
            printf("\t4.2A9B (Vote15%%)\n");
        }

    }

    case 2:
    {

        printf("\n\nYour ans:");


        scanf("%d",&q2);
        time(&time2);
        t=difftime(time2,time1);
        printf("Your answering time is %0.2lf\n",t);
        if(t>50)
        {
            printf("!!! Timed out !!!\n");
            c=c+1;

            printf("\nPress <M> for main menu:\n");
            scanf("%s",&mnum3);
            system("cls");
            main();
        }






        if(q2==1)
        {


            printf("Your ans is correct!\n\n");

            s=s+400;
            printf("Now your money is %d TK",s);



            Sleep(2500);
            system("CLS");

        }
        else

        {
            printf("Your ans is incorrect/n");
            reg.score=s;
            printf("\n\n\nyour score is %d",reg.score);


            ptr=fopen("score.txt", "a");

            fwrite(&reg,sizeof(reg),1,ptr);
            fclose(ptr);

            write_name();
            printf("\nPress <M> for main menu:\n");
            scanf("%s",&mnum3);
            system("cls");
            main();
        }


    }






    printf("\n\n3.Which bird has the fastest rate of flapping it's wings?\n");
    printf("1.Ostrich");
    printf("\t2.Humming Bird");
    printf("\t3.Penguin");
    printf("\t4.Kingfisher\n");
    time(&time1);

    printf("\n  >>1.Lifelines!");
    printf("\n  >>2.Direct answer!\n=");

    scanf("%d",&lifechoose3);

    switch(lifechoose3)

    {
    case 1:
    {
        ///////////////////////////linelines//////////////////////////
        printf("\nChoose a lifeline!\n");

        printf("1. 50:50\n");
        printf("2. Phone a Friend \n");
        printf("3. Audience poll \n");
        scanf("%d",&life3);

        if (life3==1)
        {
            printf("\n\n3.Which bird has the fastest rate of flapping it's wings?\n");
            printf("1.Ostrich");
            printf("\t2.Humming Bird");
        }
        else if(life3==2)
        {
            printf("\n\nYour friend is confused between option 2 and  3\n");
        }
        else
        {
            printf("\n\n3.Which bird has the fastest rate of flapping it's wings?\n");
            printf("1.Ostrich (Vote 20%%)");
            printf("\t2.Humming Bird (Vote 30%%)");
            printf("\t3.Penguin (Vote 20%%)");
            printf("\t4.Kingfisher (Vote 30%%)\n");
        }

    }

    case 2:
    {

        printf("\n\nYour ans:");


        scanf("%d",&q3);

        time(&time2);
        t=difftime(time2,time1);
        printf("Your answering time is %0.2lf\n",t);
        if(t>50)
        {
            printf("!!! Timed out !!!\n");
            c=c+1;

            printf("\nPress <M> for main menu:\n");
            scanf("%s",&mnum3);
            system("cls");
            main();
        }



        if(q3==2)
        {
            printf("Your ans is correct!\n\n");

            s=s+500;
            printf("Now your money is %d TK",s);


            Sleep(2500);
            system("CLS");
        }
        else

        {
            printf("Your ans is incorrect/n");
            reg.score=s;
            printf("\n\n\nyour score is %d",reg.score);


            ptr=fopen("score.txt", "a");

            fwrite(&reg,sizeof(reg),1,ptr);
            fclose(ptr);

            write_name();
            printf("\nPress <M> for main menu:\n");
            scanf("%s",&mnum3);
            system("cls");
            main();
        }


    }
    printf("\n\n4.what dose code '007' means?\n");

    printf("1.License to destroy");
    printf("\t2.License to kill");
    printf("\t3.License to arrest");
    printf("\t4.License to steal\n");
    time(&time1);

    printf("\n  >>1.Lifelines!");
    printf("\n  >>2.Direct answer!\n=");
    scanf("%d",&lifechoose4);

    switch(lifechoose4)

    {
    case 1:
    {
        ///////////////////////////linelines//////////////////////////
        printf("\nChoose a lifeline!\n");

        printf("1. 50:50\n");
        printf("2. Phone a Friend \n");
        printf("3. Audience poll \n");
        scanf("%d",&life4);

        if (life4==1)
        {
            printf("\n\n4.what dose code '007' means?\n");

            printf("1.License to destroy");
            printf("\t2.License to kill");
        }

        else if(life3==2)
        {
            printf("\n\nYour friend is confused between option 2 and  1\n");
        }
        else
        {
            printf("\n\n4.what dose code '007' means?\n");

            printf("1.License to destroy (%Vote 50%)");
            printf("\t2.License to kill  (%Vote 30%)");
            printf("\t3.License to arrest (%Vote 10%)");
            printf("\t4.License to steal  (%Vote 10%)\n");
        }

    }

    case 2:
    {

        printf("\n\nYour ans:");


        scanf("%d",&q4);
        time(&time2);
        t=difftime(time2,time1);
        printf("Your answering time is %0.2lf\n",t);
        if(t>40)
        {
            printf("!!! Timed out !!!\n");
            c=c+1;

            printf("\nPress <M> for main menu:\n");
            scanf("%s",&mnum3);
            system("cls");
            main();
        }



        if(q4==2)
        {
            printf("Your ans is correct!\n\n");

            s=s+1000;
            printf("Now your money is %d TK",s);

            Sleep(2500);
            system("CLS");
        }
        else

        {
            printf("Your ans is incorrect/n");
            reg.score=s;
            printf("\n\n\nyour score is %d",reg.score);


            ptr=fopen("score.txt", "a");

            fwrite(&reg,sizeof(reg),1,ptr);
            fclose(ptr);

            write_name();
            printf("\nPress <M> for main menu:\n");
            scanf("%s",&mnum3);
            system("cls");
            main();
        }


    }



    printf("\n\n5.Whom do you think father of modern computer?\n");
    printf("1.Alecgender Fleming");
    printf("\t2.Albert Einsteain");
    printf("\t3.Thomas Alva Edison");
    printf("\t4.Charls Babbage\n");
    time(&time1);

    printf("\n  >>1.Lifelines!");
    printf("\n  >>2.Direct answer!\n=");

    scanf("%d",&lifechoose5);

    switch(lifechoose5)

    {
    case 1:
    {
        ///////////////////////////linelines//////////////////////////
        printf("\nChoose a lifeline!\n");

        printf("1. 50:50\n");
        printf("2. Phone a Friend \n");
        printf("3. Audience poll \n");
        scanf("%d",&life5);

        if (life5==1)
        {
            printf("\n\n5.Whom do you think father of modern computer?\n");
            printf("1.Alecgender Fleming");
            printf("\t4.Charls Babbage\n");
        }
        else if(life5==2)
        {
            printf("\n\nYour friend is confused between option 4 and  1\n");
        }
        else
        {
            printf("\n\n5.Whom do you think father of modern computer?\n");
            printf("1.Alecgender Fleming (Vote 60%%)");
            printf("\t2.Albert  (Vote 10%%)");
            printf("\t3.Thomas Alva Edison (Vote 10%%)");
            printf("\t4.Charls Babbage (Vote 20%%)\n");
        }

    }

    case 2:
    {

        printf("\n\nYour ans:");


        scanf("%d",&q5);
        time(&time2);
        t=difftime(time2,time1);
        printf("Your answering time is %0.2lf\n",t);
        if(t>40)
        {
            printf("!!! Timed out !!!\n");
            c=c+1;

            printf("\nPress <M> for main menu:\n");
            scanf("%s",&mnum3);
            system("cls");
            main();
        }



        if(q5==4)
        {
            printf("Your ans is correct!\n\n");

            s=s+2000;
            printf("Now your money is %d TK",s);

            Sleep(2500);
            system("CLS");
        }
        else

        { printf("Your ans is incorrect/n");
            reg.score=s;
            printf("\n\n\nyour score is %d",reg.score);


            ptr=fopen("score.txt", "a");

            fwrite(&reg,sizeof(reg),1,ptr);
            fclose(ptr);

            write_name();
            printf("\nPress <M> for main menu:\n");
            scanf("%s",&mnum3);
            system("cls");
            main();
        }


    }





    printf("\n\n6.What is the perion of frist generation computer?\n");
    printf("1.1940-1956");
    printf("\t2.1966-1972");
    printf("\t3.1990-1997");
    printf("\t4.1930-1940\n");

    time(&time1);

    printf("\n  >>1.Lifelines!");
    printf("\n  >>2.Direct answer!\n=");

    scanf("%d",&lifechoose6);

    switch(lifechoose6)

    {
    case 1:
    {
        ///////////////////////////linelines//////////////////////////
        printf("\nChoose a lifeline!\n");

        printf("1. 50:50\n");
        printf("2. Phone a Friend \n");
        printf("3. Audience poll \n");
        scanf("%d",&life6);

        if (life6==1)
        {
            printf("\n\n6.What is the perion of frist generation computer?\n");
            printf("1.1940-1956");
            printf("\t2.1966-1972");
        }
        else if(life6==2)
        {
            printf("\n\nYour friend is confused between option 1 and  4\n");
        }
        else
        {
            printf("\n\n6.What is the perion of frist generation computer?\n");
            printf("1.1940-1956 (Vote 20%%)");
            printf("\t2.1966-1972 (Vote 30%%)");
            printf("\t3.1990-1997 (Vote 10%%)");
            printf("\t4.1930-1940 (Vote 40%%)\n");
        }

    }

    case 2:
    {

        printf("\n\nYour ans:");


        scanf("%d",&q6);
        time(&time2);
        t=difftime(time2,time1);
        printf("Your answering time is %0.2lf\n",t);
        if(t>40)
        {
            printf("!!! Timed out !!!\n");
            c=c+1;

            printf("\nPress <M> for main menu:\n");
            scanf("%s",&mnum3);
            system("cls");
            main();
        }




        if(q6==1)
        {
            printf("Your ans is correct!\n\n");


            s=s+6000;
            printf("Now your money is %d TK",s);

            Sleep(2500);
            system("CLS");
        }
        else

        {
            printf("Your ans is incorrect/n");
            reg.score=s;
            printf("\n\n\nyour score is %d",reg.score);


            ptr=fopen("score.txt", "a");

            fwrite(&reg,sizeof(reg),1,ptr);
            fclose(ptr);

            write_name();
            printf("\nPress <M> for main menu:\n");
            scanf("%s",&mnum3);
            system("cls");
            main();
        }


    }

    printf("\n\n7.A byte is equal to how many bits.\n");
    printf("1.8");
    printf("\t2.32");
    printf("\t3.1080");
    printf("\t4.140\n");

    time(&time1);

    printf("\n  >>1.Lifelines!");
    printf("\n  >>2.Direct answer!\n=");

    scanf("%d",&lifechoose7);

    switch(lifechoose7)

    {
    case 1:
    {
        ///////////////////////////linelines//////////////////////////
        printf("\nChoose a lifeline!\n");

        printf("1. 50:50\n");
        printf("2. Phone a Friend \n");
        printf("3. Audience poll \n");
        scanf("%d",&life7);

        if (life7==1)
        {
            printf("\n\n7.A byte is equal to how many bits.\n");
            printf("1.8");
            printf("\t2.32");
        }
        else if(life7==2)
        {
            printf("\n\nYour friend is confused between option 2 and  3\n");
        }
        else
        {
            printf("\n\n7.A byte is equal to how many bits.\n");
            printf("1.8 (Vote 5%%)");
            printf("\t2.32 (Vote 10%%)");
            printf("\t3.1080 (Vote 50%%)");
            printf("\t4.140 (Vote 35%%)\n");
        }

    }

    case 2:
    {

        printf("\n\nYour ans:");


        scanf("%d",&q7);
        time(&time2);
        t=difftime(time2,time1);
        printf("Your answering time is %0.2lf\n",t);
        if(t>30)
        {
            printf("!!! Timed out !!!\n");
            c=c+1;

            printf("\nPress <M> for main menu:\n");
            scanf("%s",&mnum3);
            system("cls");
            main();
        }



        if(q7==1)
        {
            printf("Your ans is correct!\n\n");

            s=s+10000;
            printf("Now your money is %d TK",s);

            Sleep(2500);
            system("CLS");
        }
        else

        {
            printf("Your ans is incorrect/n");
            reg.score=s;
            printf("\n\n\nyour score is %d",reg.score);


            ptr=fopen("score.txt", "a");

            fwrite(&reg,sizeof(reg),1,ptr);
            fclose(ptr);

            write_name();
            printf("\nPress <M> for main menu:\n");
            scanf("%s",&mnum3);
            system("cls");
            main();
        }


    }


    printf("\n\n8.Who invented the term BIOS.\n");
    printf("1.Gary Kildall");
    printf("\t2.Thomas Harfild");
    printf("\t3.Del Bios");
    printf("\t4.Atmos Albart\n");

    time(&time2);

    printf("\n  >>1.Lifelines!");
    printf("\n  >>2.Direct answer!\n=");

    scanf("%d",&lifechoose8);

    switch(lifechoose8)

    {
    case 1:
    {
        ///////////////////////////linelines//////////////////////////
        printf("\nChoose a lifeline!\n");

        printf("1. 50:50\n");
        printf("2. Phone a Friend \n");
        printf("3. Audience poll \n");
        scanf("%d",&life8);

        if (life8==1)
        {
            printf("\n\n8.Who invented the term BIOS.\n");
            printf("1.Gary Kildall");
            printf("\t2.Thomas Harfild");
        }
        else if(life8==2)
        {
            printf("\n\nYour friend is confused between option 2 and  1\n");
        }
        else
        {
            printf("\n\n8.Who invented the term BIOS.\n");
            printf("1.Gary Kildall (Vote 40%%)");
            printf("\t2.Thomas Harfild (Vote 50%%)");
            printf("\t3.Del Bios (Vote 5%%)");
            printf("\t4.Atmos Albart (Vote 5%%)\n");
        }

    }

    case 2:
    {

        printf("\n\nYour ans:");


        scanf("%d",&q8);

        time(&time2);
        t=difftime(time2,time1);
        printf("Your answering time is %0.2lf\n",t);
        if(t>30)
        {
            printf("!!! Timed out !!!\n");
            c=c+1;

            printf("\nPress <M> for main menu:\n");
            scanf("%s",&mnum3);
            system("cls");
            main();
        }



        if(q8==1)
        {
            printf("Your ans is correct!\n\n");

            s=s+10000;
            printf("Now your money is %d TK",s);

            Sleep(2500);
            system("CLS");
        }
        else

        {
            printf("Your ans is incorrect/n");
            reg.score=s;
            printf("\n\n\nyour score is %d",reg.score);


            ptr=fopen("score.txt", "a");

            fwrite(&reg,sizeof(reg),1,ptr);
            fclose(ptr);

            write_name();
            printf("\nPress <M> for main menu:\n");
            scanf("%s",&mnum3);
            system("cls");
            main();
        }


    }


    printf("\n\n9. Which of the following statement is correct?\n");
    printf("1.Virus is a part of Software.");
    printf("\t2.Virus is an operating system.");
    printf("\t3.Internet dose not allow virus to spread.");
    printf("\t4.Virus is a another name of game.\n");

    time(&time1);

    printf("\n  >>1.Lifelines!");
    printf("\n  >>2.Direct answer!\n=");
    scanf("%d",&lifechoose9);

    switch(lifechoose9)

    {
    case 1:
    {
        ///////////////////////////linelines//////////////////////////
        printf("\nChoose a lifeline!\n");

        printf("1. 50:50\n");
        printf("2. Phone a Friend \n");
        printf("3. Audience poll \n");
        scanf("%d",&life9);

        if (life9==1)
        {
            printf("\n\n9. Which of the following statement is correct?\n");
            printf("1.Virus is a part of Software.");
            printf("\t2.Virus is an operating system.");
        }
        else if(life9==2)
        {
            printf("\n\nYour friend is confused between option 2 and  1\n");
        }
        else
        {
            printf("\n\n9. Which of the following statement is correct?\n");
            printf("1.Virus is a part of Software. (Vote 50%%)");
            printf("\t2.Virus is an operating system.(Vote 10%%)");
            printf("\t3.Internet dose not allow virus to spread.(Vote 20%%)");
            printf("\t4.Virus is a another name of game.(Vote 10%%)\n");

        }

    }

    case 2:
    {

        printf("\n\nYour ans:");


        scanf("%d",&q9);
        time(&time2);
        t=difftime(time2,time1);
        printf("Your answering time is %0.2lf\n",t);
        if(t>30)
        {
            printf("!!! Timed out !!!\n");
            c=c+1;

            printf("\nPress <M> for main menu:\n");
            scanf("%s",&mnum3);
            system("cls");
            main();
        }



        if(q9==1)
        {
            printf("Your ans is correct!\n\n");

            s=s+20000;
            printf("Now your money is %d TK",s);

            Sleep(2500);
            system("CLS");
        }
        else

        {  printf("Your ans is incorrect/n");
            reg.score=s;
            printf("\n\n\nyour score is %d",reg.score);


            ptr=fopen("score.txt", "a");

            fwrite(&reg,sizeof(reg),1,ptr);
            fclose(ptr);

            write_name();
            printf("\nPress <M> for main menu:\n");
            scanf("%s",&mnum3);
            system("cls");
            main();
        }


    }

    printf("\n\n10.Which is the following is used in pencils.\n");
    printf("1.Graphite");
    printf("\t2.Charcoal");
    printf("\t3.Silicon.");
    printf("\t4.Phosphorus\n");

    time(&time1);

    printf("\n  >>1.Lifelines!");
    printf("\n  >>2.Direct answer!\n=");

    scanf("%d",&lifechoose10);

    switch(lifechoose10)

    {
    case 1:
    {
        ///////////////////////////linelines//////////////////////////
        printf("\nChoose a lifeline!\n");

        printf("1. 50:50\n");
        printf("2. Phone a Friend \n");
        printf("3. Audience poll \n");
        scanf("%d",&life10);

        if (life10==1)
        {
            printf("\n\n10.Which is the following is used in pencils.\n");
            printf("1.Graphite");
            printf("\t2.Charcoal");
        }
        else if(life10==2)
        {
            printf("\n\nYour friend is confused between option 2 and  1\n");
        }
        else
        {
            printf("\n\n10.Which is the following is used in pencils.\n");
            printf("1.Graphite (Vote 10%%)");
            printf("\t2.Charcoal(Vote 20%%)");
            printf("\t3.Silicon (Vote 40%%)");
            printf("\t4.Phosphorus (Vote 30%%)\n");

        }

    }

    case 2:
    {

        printf("\n\nYour ans:");


        scanf("%d",&q10);

        time(&time2);
        t=difftime(time2,time1);
        printf("Your answering time is %0.2lf\n",t);
        if(t>25)
        {
            printf("!!! Timed out !!!\n");
            c=c+1;

            printf("\nPress <M> for main menu:\n");
            scanf("%s",&mnum3);
            system("cls");
            main();
        }



        if(q10==1)
        {
            printf("Your ans is correct!\n\n");

            s=s+20000;
            printf("Now your money is %d TK",s);

            Sleep(2500);
            system("CLS");
        }
        else

        {
            printf("Your ans is incorrect/n");
            reg.score=s;
            printf("\n\n\nyour score is %d",reg.score);


            ptr=fopen("score.txt", "a");

            fwrite(&reg,sizeof(reg),1,ptr);
            fclose(ptr);

            write_name();
            printf("\nPress <M> for main menu:\n");
            scanf("%s",&mnum3);
            system("cls");
            main();
        }


    }

    printf("\n\n11.Who invented Ball point pen?\n");
    printf("1.Biro Brothers");
    printf("\t2.Bicc brothers");
    printf("\t3.Waterman Brothers");
    printf("\t4.Write Brothers\n");

    time(&time1);


    printf("\n  >>1.Lifelines!");
    printf("\n  >>2.Direct answer!\n=");

    scanf("%d",&lifechoose11);

    switch(lifechoose11)

    {
    case 1:
    {
        ///////////////////////////linelines//////////////////////////
        printf("\nChoose a lifeline!\n");

        printf("1. 50:50\n");
        printf("2. Phone a Friend \n");
        printf("3. Audience poll \n");
        scanf("%d",&life11);

        if (life11==1)
        {
            printf("\n\n11.Who invented Ball point pen?\n");
            printf("1.Biro Brothers");
            printf("\t2.Bicc brothers");
        }
        else if(life11==2)
        {
            printf("\n\nYour friend is confused between option 4 and  3\n");
        }
        else
        {
            printf("\n\n11.Who invented Ball point pen?\n");
            printf("1.Biro Brothers (Vote 10%)");
            printf("\t2.Bicc brothers (Vote 40%)");
            printf("\t3.Waterman Brothers (Vote 30%)");
            printf("\t4.Write Brothers (Vote 10%)\n");

        }

    }

    case 2:
    {

        printf("\n\nYour ans:");


        scanf("%d",&q11);


        time(&time2);
        t=difftime(time2,time1);
        printf("Your answering time is %0.2lf\n",t);
        if(t>25)
        {
            printf("!!! Timed out !!!\n");
            c=c+1;

            printf("\nPress <M> for main menu:\n");
            scanf("%s",&mnum3);
            system("cls");
            main();
        }



        if(q11==1)
        {
            printf("Your ans is correct!\n\n");

            s=s+30000;
            printf("Now your money is %d TK",s);

            Sleep(2500);
            system("CLS");
        }
        else

        {  printf("Your ans is incorrect/n");
            reg.score=s;
            printf("\n\n\nyour score is %d",reg.score);


            ptr=fopen("score.txt", "a");

            fwrite(&reg,sizeof(reg),1,ptr);
            fclose(ptr);

            write_name();
            printf("\nPress <M> for main menu:\n");
            scanf("%s",&mnum3);
            system("cls");
            main();
        }


    }
    printf("\n\n12.Which of the following is used as a moderator in nuclear reactor?\n");
    printf("1.Thorium");
    printf("\t2.Graphite");
    printf("\t3.Radium");
    printf("\t4.Ordinary Water\n");

    time(&time1);

    printf("\n  >>1.Lifelines!");
    printf("\n  >>2.Direct answer!\n=");

    scanf("%d",&lifechoose12);

    switch(lifechoose12)

    {
    case 1:
    {
        ///////////////////////////linelines//////////////////////////
        printf("\nChoose a lifeline!\n");

        printf("1. 50:50\n");
        printf("2. Phone a Friend \n");
        printf("3. Audience poll \n");
        scanf("%d",&life12);

        if (life12==1)
        {
            printf("\n\n12.Which of the following is used as a moderator in nuclear reactor?\n");
            printf("1.Thorium");
            printf("\t2.Graphite");
        }
        else if(life12==2)
        {
            printf("\n\nYour friend is confused between option 3 and  4\n");
        }
        else
        {
            printf("\n\n12.Which of the following is used as a moderator in nuclear reactor?\n");
            printf("1.Thorium (Vote 50%)");
            printf("\t2.Graphite (Vote 20%)");
            printf("\t3.Radium (Vote 20%)");
            printf("\t4.Ordinary Water\n (Vote 10%)");

        }

    }

    case 2:
    {

        printf("\n\nYour ans:");


        scanf("%d",&q12);

        time(&time2);
        t=difftime(time2,time1);
        printf("Your answering time is %0.2lf\n",t);
        if(t>25)
        {
            printf("!!! Timed out !!!\n");
            c=c+1;

            printf("\nPress <M> for main menu:\n");
            scanf("%s",&mnum3);
            system("cls");
            main();
        }



        if(q12==2)
        {
            printf("                                                !!!!Congratulations!!!!\n\nBrilliant performance");
            printf("                                                >>You are a millionaire now!!!!\n\n");

            printf("Your ans is correct!\n\n");

            s=s+900000;
            printf("Now your money is %d TK",s);

            Sleep(2500);
            system("CLS");
        }
        else

        {
            printf("Your ans is incorrect\nSo, sad. You just missed at last stage!");
            reg.score=s;
            printf("\n\n\nyour score is %d",reg.score);


            ptr=fopen("score.txt", "a");

            fwrite(&reg,sizeof(reg),1,ptr);
            fclose(ptr);

            write_name();
            printf("\nPress <M> for main menu:\n");
            scanf("%s",&mnum3);
            system("cls");
            main();
        }


    }


    }
    }
    }
    }
    }
    }
    }
    }
    }
    }
    }

    reg.score=s;
    printf("\n\n\nyour score is %d",reg.score);
///////////////////////////////*****Play game end*****///////////////////////////
}

display_all()
{
    char mnum11;
   // FILE *f;
    system("cls");
    f=fopen("scorec.txt","r");
    fread(&reg,sizeof(reg),1,f);
    fclose(f);
    printf("\n\n\n\n");
    printf("                   \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2                                                                                \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
    printf("                   \xB2\xB2                                                                                                  \xB2\xB2\n");
    printf("\t\t\t\t                        \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
    printf("                                                        \xB2\xB2 DISPLAY ALL RECORD \xB2\xB2\n");
    printf("\t\t\t\t                        \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n\n");
    f=fopen("scorec.txt","rb");
    while((fread(&reg,sizeof(reg),1,f))>0)
    {




        printf("\n                                                          Player Name  : %s",reg.name2);
        printf("\n                                                          Wining money : %d",reg.score2);
        printf("\n                                                          A/C no. : %d",reg.ac2);

        printf("\n\n                                                  ====================================\n");
        getch();
    }
    fclose(f);
    printf("\n          Press <M> for main menu:\n");
    scanf("%s",&mnum11);
    system("cls");
    main();
}

write_name()
{
    FILE *f;

    f=fopen("scorec.txt","a+");
rep:
    fflush(stdin);
    printf("\n\n    >>Enter your user name: ");
    scanf("%s",&reg.name2);

    fflush(stdin);
    printf("\n  >>The money you have won: ");



    scanf("%d",&reg.score2);

    printf("\n  >>Enter your A/c no. by which you register your account: ");
    scanf("%d",&reg.ac2);
    if(reg.score2==reg.score)
        fwrite(&reg,sizeof(reg),1,f);
    else
    {

        printf("\n Incorrect information!!!\n Please Enter the correct information");

        goto rep;

    }


    fclose(f);

}
