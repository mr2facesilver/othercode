if {[catch {
	package require tdbc::mysql
	tdbc::mysql::connection create con -user [lindex $argv 2] -database [lindex $argv 1] -password [lindex $argv 3]
	set st [con prepare {select * from students where lastname like "D%"}]
	set results [$st allrows]
	puts "                                                                 "
	puts "       tnum	  firstname      lastname dateofbirth			"
	puts "                                                                 "
	foreach row $results {
			foreach {col_name col_val} $row {
					puts -nonewline [format "%13s" $col_val]
				}
			puts ""
		}
	con close
} errmsg]} {
	puts $errmsg
	}
