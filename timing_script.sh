#!/bin/tcsh

echo "=========== insertOnly ============"

foreach x (`seq 0 2`) #`seq 0 2` = 0 1 2
	echo "Running it in mode $x";
	foreach y (insertOnly*) #Uses all inputfiles starting with "insertsearch"
		echo "Running a.out $x < $y (5 repetitions)"
		foreach t (`seq 0 4`) #5 Repetitions
			#(/usr/bin/time -f %e nice -n 19 a.out $x < $y > /dev/null) | cut -f1 -d"u"
			(/usr/bin/time -f %e nice -n 19 a.out $x < $y > /dev/null) | cut -f1 -d"u"
		end
	end
end
