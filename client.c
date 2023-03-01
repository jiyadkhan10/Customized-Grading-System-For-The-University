#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>
#include <netinet/in.h>
int main() {
	
	//char request[256] = "Hello I am Client are you there";
	
        char file_names[200]="NaveedKhurshid SubhanUllah ";
        char student_details[1000];
	char buf[50]="student";
	char buf1[50]="teacher";
	char name[50];
	char roll[10];
	char opt[10];
	char name_teacher[50];
	int user;
	char data[1000];
	int n ;
	char b [50];
	char course[50];
	char exist[20];
	char send_cc[100];
	int found=0;
	char no_r[5];
        char send_c[50];
        int cour=0;
	// create the socket
	int sock;
	sock = socket(AF_INET, SOCK_STREAM, 0);
	
	//setup an address
	struct sockaddr_in server_address;
	server_address.sin_family = AF_INET;
	server_address.sin_addr.s_addr = INADDR_ANY;
	server_address.sin_port = htons(3001);

	connect(sock, (struct sockaddr *) &server_address, sizeof(server_address));
	printf("If you are a teacher enter 1 , if you are a student enter 0\n");
	scanf("%d",&user);
	
	if (user == 0)
        {
                
                        send(sock, buf, sizeof(buf), 0);
                        printf("Enter roll number in format: yyi-xx: ");
		        scanf("%s",roll);
		        
		        send(sock, roll, sizeof(roll), 0);
		        recv(sock, &exist, sizeof(exist), 0);
		        
		        int cmp= strcmp(exist,"yes");
		        if (cmp==0){
		                printf("Enter the Course: ");
		                scanf("%s",course);
		                
		                send(sock, course, sizeof(course), 0);
		                strcpy(exist," ");
		                
		                recv(sock, &exist, sizeof(exist), 0);
		                int cmp1= strcmp(exist,"no");
		                
		                if (cmp1 == 0)
		                {
		                        printf("Course Does not EXIST!\n");
		                        
		                }
		                else
		                {
		                        printf("%s: %s",course,exist);
		                        
		                }
		                
		         
		                //recv(sock, &data, sizeof(data), 0);
		                //printf("s\n",data);
		        
		        }
	               else
	               {
	                        printf("Roll Number does not exist\n");
	                        
	                
	               }
	               
	               /*printf("\n\nTo exit enter 'y' : to continue press 'n' \n");
	               char ans[5];
	               scanf("%s",ans);
	               
	               int cc= strcmp(ans,"n");
	               if (cc !=0 )
	               {
	                        break;
	               }*/
	               
              
                
        }
        
        if (user == 1)
        {
                
                                send(sock, buf1, sizeof(buf1), 0);
                                printf("Enter your name: ");
                                scanf("%s",name_teacher);
                                
                                printf("You entered: %s",name_teacher);
                                send(sock, name_teacher, sizeof(name_teacher), 0);
                                
                               
	                                        
	                                        char *ne_f= strtok(file_names," ");
	                                      while(ne_f)
	                                      {
	                                                int d=strcmp(ne_f,name_teacher);
	                                            
	                                                if (d == 0)
	                                                {
	                                                        
	                                                        found=1;
	                                                      
	                                                        break;
	                                                }
	                                                
	                                                if (d !=0)
	                                                {
	                                                       found=0;
	                                                }
	                                         ne_f = strtok(NULL, " ");
	                                      }
                
                
                                if (found == 1)
                                {
                                        printf("To add press 1 : To view press 0 : ");
                                        int us=0;
                                        scanf("%d",&us);
                                        
                                        if (us == 1)
                                        {
                                                FILE* fp;
				                        char name_T[100];
				                        strcpy(name_T," ");
				                        strcat(name_T,name_teacher);
				                        strcat(name_T,".csv");
				                        fp=fopen(name_T,"a+");
                                                strcpy(student_details," ");
                                                
                                                printf("Enter Roll Number: ");
				                        char roll_numb[50];
				                        
				                        scanf("%s",roll_numb);
				                        
				                        char obt_marks[cour];
				                        char total_marks[cour];
				                        
				                        int obt_marks1=0;
				                        int total_marks1=0;
				                        
				                        char student_details[500];
				                        strcpy(student_details," ");
				                        char buffer[1024];
				                        int row_c=0;
				                        while (fgets(buffer,
							                1024, fp)) {
							                row_c++;}
							                
					                row_c-=3;
					                char row_u[10];
					                
					                sprintf(row_u,"%d",row_c);
					                
				                        strcat(student_details,row_u);
				                        strcat(student_details,",");
				                        strcat(student_details,roll_numb);
				                        strcat(student_details,",");
				                        strcat(student_details,",");
				                        for ( int r=0; r <cour; r++)
				                        {
					                        printf("\nEnter obtained Marks for course %d: ",r+1);
					                        scanf("%s",&obt_marks[r]);
					                        int g=atoi(&obt_marks[r]);
					                        obt_marks1= obt_marks1 +g ;
					                       
					                        
					                        strcat(student_details,&obt_marks[r]);
					                        strcat(student_details,",");
					                        
					                        printf("\nEnter Total Marks for course %d: ",r+1);
					                        scanf("%s",&total_marks[r]);
					                        
					                        g=atoi(&total_marks[r]);
					                        total_marks1= total_marks1 + g;
					                        
				                        }
				                        
				                        char bug[50];
				                        sprintf(bug,"%d",obt_marks1);
				                         printf("sbhdsuf%s",bug);
				                         
				                        strcat(student_details,bug);
				                        strcat(student_details,",");
				                        strcpy(bug," ");
				                        sprintf(bug,"%d",total_marks1);
				                        strcat(student_details,bug);
				                        strcat(student_details,",");
				                        
				                        
					                fprintf(fp,"\n%s",student_details);
					                fclose(fp);
                                        }
                                        else
                                        {
                                                int r_num=0;
                                               
                                                char buffer[1024];
                                                        FILE* fp;
				                        char name_T[100];
				                        
				                        //strcpy(name_T," ");
				                        strcat(name_T,name_teacher);
				                        strcat(name_T,".csv");
				                        
				                        fp=fopen(name_T,"a+");
				                int row = 0;
				                int column = 0;
				                
				                while (fgets(buffer,
							                1024, fp)) {
					               
						                
					                        printf("%s  ", buffer);
						                continue;
					                }

					               
				                

				                
				                fclose(fp);
				                exit(0);
				           }
				                
			                }
		                        
                                
                
                recv(sock, &no_r, sizeof(no_r), 0);
                int c= strcmp(no_r,"no");
                
                                        if (c == 0 && found == 0)
                                        {
                                                printf("The file does not EXISTS!\n");
                                                 
                                                 printf("To create file enter 'y' else 'n' \n");
                                                 char res[5];
                                                 scanf("%s",res);
                                                 
                                                 int c1= strcmp(res,"y");
                                                 if (c1 == 0)
                                                 {
                                                        send(sock, res, sizeof(res), 0);
                                                        printf("Enter the number of courses: ");
                                                        
                                                        scanf("%d",&cour);
                                                        
                                                        char cour_send[10];
                                                        sprintf(cour_send,"%d",cour);
                                                        send(sock, cour_send, sizeof(cour_send), 0);
                                                        
                                                        strcpy(send_cc," ");
                                                        
                                                        char send1[50];
                                                        //send(sock, cour, sizeof(cour), 0);
                                                        for (int c =0; c < cour; c++)
                                                        {
                                                                printf("Enter course: ");
                                                                
                                                                scanf("%s",send1);
                                                                strcat(send_cc,send1);
                                                                strcat(send_cc,",");
                                                                strcpy(send1," ");
                                                                
                                                        }
                                                        printf("You entered: %s\n",send_cc);
                                                        send(sock, send_cc, sizeof(send_cc), 0);
                                                        
                                                        printf("Do you want to add any data: press 'y' else 'e' : ");
                                                        char d_s[5];
                                                        scanf("%s",d_s);
                                                        int cp= strcmp(d_s,"y");
                                                        if( cp ==0 )
                                                        {
                                                                //send(sock, res, sizeof(res), 0);
                                                                printf("Enter Roll Number: ");
				                                char roll_numb[50];
				                                
				                                scanf("%s",roll_numb);
				                                
				                                char obt_marks[cour];
				                                char total_marks[cour];
				                                
				                                int obt_marks1=0;
				                                int total_marks1=0;
				                                
				                                char student_details[500];
				                                strcpy(student_details," ");
				                                
				                                strcat(student_details,"1,");
				                                strcat(student_details,roll_numb);
				                                strcat(student_details,",");
				                                strcat(student_details,",");
				                                for ( int r=0; r <cour; r++)
				                                {
					                                printf("\nEnter obtained Marks for course %d: ",r+1);
					                                scanf("%s",&obt_marks[r]);
					                                int g=atoi(&obt_marks[r]);
					                                obt_marks1= obt_marks1 +g ;
					                               
					                                
					                                strcat(student_details,&obt_marks[r]);
					                                strcat(student_details,",");
					                                
					                                printf("\nEnter Total Marks for course %d: ",r+1);
					                                scanf("%s",&total_marks[r]);
					                                
					                                g=atoi(&total_marks[r]);
					                                total_marks1= total_marks1 + g;
					                                
				                                }
				                                
				                                char bug[50];
				                                sprintf(bug,"%d",obt_marks1);
				                                
				                                 
				                                strcat(student_details,bug);
				                                strcat(student_details,",");
				                                strcpy(bug," ");
				                                sprintf(bug,"%d",total_marks1);
				                                strcat(student_details,bug);
				                                strcat(student_details,",");
				                                
				                                FILE* fp;
				                                char name_T[100];
				                                strcpy(name_T," ");
				                                strcat(name_T,name_teacher);
				                                strcat(name_T,".csv");
				                                fp=fopen(name_T,"a+");
					                        fprintf(fp,"\n%s",student_details);
					                        fclose(fp);
				                                
				                                //send(sock, student_details, sizeof(student_details), 0);
                                                        }
                                                        
                                                 }
                                                 
                                                 else
                                                 {
                                                        exit(0);
                                                 }
                                        }
                                        
                                        else
                                        {
                                        
                                               printf("To add data press 1 , to view data press 2");
                                               int da=0;
                                               scanf("%d",&da);
                                               
                                               if (da ==1 )
                                               {
                                                        printf("Enter Roll Number: ");
				                                char roll_numb[50];
				                                
				                                scanf("%s",roll_numb);
				                                
				                                char obt_marks[cour];
				                                char total_marks[cour];
				                                
				                                int obt_marks1=0;
				                                int total_marks1=0;
				                                
				                                char student_details[500];
				                                strcpy(student_details," ");
				                                
				                                strcat(student_details,"1,");
				                                strcat(student_details,roll_numb);
				                                strcat(student_details,",");
				                                
				                                for ( int r=0; r <cour; r++)
				                                {
					                                printf("\nEnter obtained Marks for course %d: ",r+1);
					                                scanf("%s",&obt_marks[r]);
					                                int g=atoi(&obt_marks[r]);
					                                obt_marks1= obt_marks1 +g ;
					                                
					                                strcat(student_details,&obt_marks[r]);
					                                strcat(student_details,",");
					                                
					                                printf("\nEnter Total Marks for course %d: ",r+1);
					                                scanf("%s",&total_marks[r]);
					                                
					                                g=atoi(&total_marks[r]);
					                                total_marks1= total_marks1 + g;
					                                
				                                }
				                                
				                                char bug[50];
				                                sprintf(bug,"%d",obt_marks1);
				                                
				                                strcat(student_details,bug);
				                                strcat(student_details,",");
				                                
				                                sprintf(bug,"%d",total_marks1);
				                                strcat(student_details,bug);
				                                strcat(student_details,",");
				                                
				                                
				                                send(sock, student_details, sizeof(student_details), 0);
                                               }
                                        }
                                        
       
       close(sock);
}
	return 0;

}
