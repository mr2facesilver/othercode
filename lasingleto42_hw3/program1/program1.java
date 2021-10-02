import java.sql.*;
import java.util.Locale;
import java.lang.String;

public class program1 {
		public static void main(String args[]){
			try {Class.forName("com.mysql.jdbc.Driver");
				String url =	 "jdbc:mysql://" + args[0] + ":3306";Connection conn = DriverManager.getConnection(url, args[2],args[3]); 
				Statement st = conn.createStatement();st.execute("DROP DATABASE IF EXISTS " + args[1]);
				st.execute("CREATE database " + args[1]);conn.close();
				
				
				conn = DriverManager.getConnection(url + "/" + args[1], args[2],args[3]);st = conn.createStatement();
				st.execute("create table students(" + 
				"tnumber char(8) PRIMARY KEY," +
				"firstname varchar(20) not null," +
				"lastname varchar(20) not null," +
				"dateofbirth date,"+
				"index(lastname)) " + 
				"ENGINE=INNODB");

				
					System.out.println(" -   -  -  -                        - - - -  -");
					System.out.println("Tnumber	    Firstname        Lastname 	     dateofbirth");
				
					System.out.println(" -   -  -  -                        - - - -  -");
				st.execute("insert into students(tnumber, firstname, lastname, dateofbirth)"+
						"values ('00001234', 'Joe', 'Smith', '1950-08-12')");					
					
				ResultSet rs = st.executeQuery("select * from students ");

	while(rs.next()){
		String tnumber = rs.getString("students.tnumber");
		String firstname = rs.getString("students.firstname");
		String lastname = rs.getString("students.lastname");
		String dateofbirth = rs.getString("students.dateofbirth");
		System.out.format("%-15s%-15s%-15s%-15s%n" , tnumber, firstname , lastname , dateofbirth);}
				System.out.println("\n");
				conn.close();
			}catch(Exception e) { 
				System.out.println(e.getMessage());}}
}
				
