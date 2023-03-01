#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <string.h>
#include <netinet/in.h>

char file_names[200]="NaveedKhurshid SubhanUllah ";
char data[500];
char student_data[500];
char roll[10];
char course[50];
char rows[200];
//char marks[500];
int count=0;
char name_teacher[100];

void readfiles()
{
	 
   	char name_f[200];
   	char string[50]=".csv";
        strcpy(rows," ");
   	strcpy(data," ");
   	strcpy(student_data," ");
   	for (int j =0,k=0; file_names[j]!='\0' ; j++)
   	{
   		if (file_names[j]!=' ')
   		{
   		
   			
   			name_f[k]=file_names[j];
   			k++;
   			
   		}
   		
   		else 
   		{
   			name_f[k]='\0';
   			
   			//printf("name%s:", name_f);
   			strcat(name_f,string);
   			
   			FILE* fp = fopen(name_f, "r");
			
			if (!fp)
				printf("Can't open file\n");

			else {
				// Here we have taken size of
				// array 1024 you can modify it
				
				char buffer[1024];

				int row = 0;
				int column = 0;
				count=0;
				char getdata[500];
				while (fgets(buffer,
							1024, fp)) {
					column = 0;
					row++;
					strcpy(getdata," ");
				 	strcat(getdata,buffer);
					// To avoid printing of column
					// names in file can be changed
					// according to need
					if (row == 1 || row ==3){
						
						if (row ==1)
						{
						        strcat(rows,buffer);
						}
						//strcat(data,"\n");
					        strcat(data,buffer);
					        
						continue;
					}

					// Splitting the data
					char* value = strtok(buffer, ", ");
					int i =1;
					while (value) {
						
						if (i==1)
						{
							value = strtok(NULL, ", ");
							column++;
							i++;
						}
				
				
						else{
				
					
					
							if (i==2)
							{
					
				
						
								int cmp= strcmp(value,roll);
								if (cmp ==0)
								{
									//printf("%s  ", value);
									count++;
									strcat(data,getdata);
									strcat(student_data,getdata);
									
									
								}
						
						         
								value = strtok(NULL, ", ");
								
								
								column++;
								i++;
				
							}
					
							else
							{
					
								
								
								break;
							}
								column++;
								i++;
					
						}
				
					}

					
				}

				
				fclose(fp);
				strcpy(name_f," ");
				k=0;
		
				
			}
		   		
		   		
		   		}
		   		
   	
   	}
   	
   	strcat(data,"\0");
   	//printf("%s\n",student_data);

}

int main() 
{

	char server_message[256];
	int number=0;
	char buf[200];
	char res[5];
	char no[5]="no";
	char yes[5]="yes";
	//char course[50];
	char name_T[100];
	char add_str[500];            	    
	char course_str[500];
	char student_details[1000];
						
	// create the server socket
	int server_socket;
	server_socket = socket(AF_INET, SOCK_STREAM, 0);

	
	// define the server address
	struct sockaddr_in server_address;
	server_address.sin_family = AF_INET;
	server_address.sin_port = htons(3001);
	server_address.sin_addr.s_addr = INADDR_ANY;

	// bind the socket to our specified IP and port
	bind(server_socket, (struct sockaddr*) &server_address, sizeof(server_address));
	listen(server_socket, 5);
	
	while(1){
	        int client_socket;
	        client_socket = accept(server_socket, NULL, NULL);
	        
	        pid_t pid;
	        pid = fork();
	        
	        if (pid == 0)
	        {
	        
	                recv(client_socket, &server_message, sizeof(server_message), 0);
	                printf("%s \n", server_message);
	                
	                int cmp= strcmp(server_message,"teacher");
	              
	                if (cmp !=0) //This is student
	                {
	                        recv(client_socket, &roll, sizeof(roll), 0);
	                        printf("%s \n", roll);
	                        
	                        readfiles();
	                        
	                        if (count != 0)
	                        {
	                                send(client_socket, yes, sizeof(yes), 0);
	                                recv(client_socket, &course, sizeof(course), 0);
	                                
	                                char *ret = strstr(data, course);
	                                //printf("dddddddd%s\n",student_data);
	                                if (ret)
	                                {
	                                        char save[100];
	                                        int comma=-1;
	                                        int comp= -33;
	                                        char marks[100];
	                                        int chec=0;
	                                        int cch=-1;
	                                        char rows2[200];
	                                        strcpy(rows2,rows);
	                                        char* v = strtok(rows2,",");
	                                        while(v)
	                                        {
	                                               cch++; 
	                                               v = strtok(NULL, ",");
	                                        }
	                                        char* value = strtok(rows, ",");
	                                        
	                                        while(value)
	                                        {
	                                                
	                                                
	                                                /*int s=strlen(value);
	                                                int s1=strlen(course);*/
	                                                if (strlen(value) == strlen(course))
	                                                {//printf(" val%s\n", value);
	                                                        for (int f=0 ; f < strlen(course) ;f++)
	                                                        {
	                                                                if (course[f]== value[f])
	                                                                {
	                                                                        chec++;
	                                                                }
	                                                        }
	                                                        
	                                                        if (chec == strlen(course))
	                                                        {
	                                                                //printf("aaa: %s %d",value,comma);
	                                                                break;
	                                                        }
	                                                        
	                                                }
	                                                
	                                                       value = strtok(NULL, ",");
	                                                       comma++;
	                                                
	                                        }
	                                        int ch=-1;
	                                        
	                                        char *value1=strtok(student_data,",");
	                                        
	                                        
	                                        while(value1)
	                                        {
	                                                
	                                                ch++;
	                                                if (ch == comma)
	                                                {
	                                                        //printf("data: %s,%d",value1,ch);
	                                                        send(client_socket, value1, sizeof(value1), 0);
	                                                        break;
	                                                        
	                                                }
	                                                value1 = strtok(NULL, ",");
	                                                
	                                        }
	                                        
                                                       
	                                       
	                                }
	                                
	                                else
	                                {
	                                        send(client_socket, no, sizeof(no), 0);
	                                }
			        	 //send(client_socket, data, sizeof(data), 0);
			        	 
	                        }
	                
	                }
	                
	                else
	                {
	                        int found=0;
	                        recv(client_socket, &name_teacher, sizeof(name_teacher), 0);  
	                            
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
	                     
	                                                   
	                      if (found ==0 )
	                      {
	                                        send(client_socket, no, sizeof(no), 0);
	                                       
	                                        
	                                        recv(client_socket, &res, sizeof(res), 0);
	                                        int v= strcmp(res,"y");
	                                        
	                                      if (v==0)
	                                      {
	                                        
	                                        
	                                        char recvi[10];
	                                        
	                                        recv(client_socket, &recvi, sizeof(recvi), 0);
	                                       
	                                        int cm= strcmp(res,"y");
	                                        char server_m[50];
	                                        
	                                        if (cm ==0)
	                                        {
	                                                
	                                                recv(client_socket, &server_m, sizeof(server_m), 0); 
						         //printf("I got %s", server_m);
	                                        }
	                                       
	                                        else
	                                        {
	                                                
	                                        }
						        
	                                        strcpy(name_T," ");
	                                        strcat(name_T,name_teacher);
						 strcat(name_T,".csv");
						
						        FILE *fp;
						        fp=fopen(name_T,"a+");
						        
						        
						strcpy(course_str," ");
						strcat(course_str,"Teacher,");
						strcat(course_str,name_teacher);
						strcat(course_str,",");
						strcat(course_str,"Course,");
						strcat(course_str,server_m);
						
						 
						fprintf(fp,"%s",course_str);
						
						strcpy(add_str," ");
						strcat(add_str,"Student,");
						strcat(add_str,"Roll Number,,");
						
						number= atoi(recvi);
						for (int i =0; i < number-1 ; i++)
						{
							
								strcat(add_str,"Marks,");
							
											
						}
						
						strcat(add_str,"Marks,");
						strcat(add_str,"Obtained,");
						strcat(add_str,"Total");
						
						
						fprintf(fp,"\n\n%s",add_str);
						fclose(fp);
						
					        /*recv(client_socket, &student_details, sizeof(student_details), 0);
					        fp=fopen(name_T,"a+");
					        fprintf(fp,"\n%s",student_details);
					        fclose(fp);*/
					        
					        strcat(file_names,name_teacher);
					        strcat(file_names," ");
						} 
						
						else
						{
						       break;
						}
						        
						        
						
	                      }
	                      
	                      else
	                      {
	                      
	                                      
	                      }
	                }
	                
	              
	               
	                //exit(0);
	        
	        }
	        
	        
	        else
	        {
	                wait(NULL);
	                close(client_socket);
	                char last[1000];
	char l[100];
	strcpy(l," ");
	FILE* fp = fopen("NaveedKhurshid.csv", "r");

	if (!fp)
		printf("Can't open file\n");

	else {
		
		char buffer[1024];

		int row = 0;
		int column = 0;

		while (fgets(buffer,
					1024, fp)) {
			column = 0;
			row++;
			if (row == 1 && row==2)
				continue;
                        if (row == 3){ strcat(l,buffer);
                        continue;}
                               
                      
			strcat(last,buffer);
				
				column++;
			


			strcat(last,"\n");
		}

		// Close the file
		fclose(fp);
	}
	
	printf("%s",last);
	
	
	char *value= strtok(l,",");
	int count=0;
	while(value)
	{
	        int c = strcmp(value,"Obtained");
	        if (c == 0)
	        
	        {
	                printf("%s",value);
	                
	        }
	        
	        count++;
	        value= strtok(NULL,",");
	}
	
	char * value1= strtok(last,",");
	int count1=0;
	float array[100];
	char save[100];
	char save1[100];
	int li=0;
	strcpy(save," ");
	strcpy(save1," ");
	while(value1)
	{
	        
	       
	        if (count == count1+1)
	        {
	                strcat(save,value1);
	                int xx=atoi(value1);
	                float x=(xx*100)/200;
	                array[li]=x;
	                printf("dbs a%f",array[li]);
	                
	                count1=0;
	        }
	        li++;
	        count1++;
	        value1= strtok(NULL,",");
	         
	}
	
	        }
	        
	       }
	        
       //close(server_socket);
	
	
       return 0;
}	       
