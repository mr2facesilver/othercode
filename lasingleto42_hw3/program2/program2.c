

#include <my_global.h>
#include <mysql.h>


void finish_with_error(MYSQL *conn)
{fprintf(stderr  , "%s\n"  , mysql_error(conn));
	mysql_close(conn);
	exit(1);
	}
	
int main(int argc, char **argv)
{
	if (argc !=5)
	{	fprintf(stderr, "Usage: host database user password \n");}
	
	MYSQL *conn = mysql_init(NULL);
	if(mysql_real_connect(conn, argv[1], argv[3], argv[4], argv[2], 0, NULL, 0) == NULL)
	{finish_with_error(conn);}
	
	if (mysql_query(conn,"INSERT INTO students(tnumber, firstname, lastname, dateofbirth) VALUES('00003256', 'John', 'Doe', '1970-07-15'),('00001423', 'Mary', 'Smith' , '1992-01-01'),('00015366', 'William', 'Williamson', '1991-05-23'),('00012345', 'Katie' , 'Did', '1992-09-27')" ))
		{
		
			finish_with_error(conn);
		}
		if(mysql_query(conn, "select * from students"))
		{
			finish_with_error(conn);
		}
				fprintf(stderr,  " ----------------------------------------------------------\n");
		fprintf(stderr,  "       tnumber	         firstname     lastname	  dateofbirth \n ");
		fprintf(stderr,  " ----------------------------------------------------------\n");
		MYSQL_RES *result = mysql_store_result(conn);
		if(result == NULL)
		{
		
			finish_with_error(conn);
		}
		int num_fields = mysql_num_fields(result);
		MYSQL_ROW row;
		
		while ((row = mysql_fetch_row(result)))
		{for (int x=0; x<num_fields; x++)
			{printf("%15s", row[x] ? row[x]  : "NULL");
			}
			printf("\n");
		
		}
		mysql_free_result(result);
		mysql_close(conn);
		exit(0);
	}
