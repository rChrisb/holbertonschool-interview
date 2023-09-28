#!/usr/bin/python3
import sys

status_codes = ["200", "301", "400", "401", "403", "404", "405", "500"]
status_count = {code: 0 for code in status_codes}
total_size = 0
line_count = 0

try:
    for line in sys.stdin:
        line = line.strip()

        parts = line.split()

        if len(parts) >= 9 and parts[-3] == "HTTP/1.1" and parts[-4] in\
                status_codes:
            status_code = parts[-4]
            file_size = parts[-1]

            try:
                file_size = int(file_size)
                total_size += file_size
                status_count[status_code] += 1
            except ValueError:
                pass

        line_count += 1

        if line_count % 10 == 0:
            print("File size: {}".format(total_size))
            for code in sorted(status_codes):
                if status_count[code] > 0:
                    print("{}: {}".format(code, status_count[code]))

except KeyboardInterrupt:
    pass

finally:
    print("File size: {}".format(total_size))
    for code in sorted(status_codes):
        if status_count[code] > 0:
            print("{}: {}".format(code, status_count[code]))
