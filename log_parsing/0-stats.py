#!/usr/bin/python3
import sys

status_codes = ["200", "301", "400", "401", "403", "404", "405", "500"]
status_count = {code: 0 for code in status_codes}
total_size = 0
line_count = 0

try:
    for line in sys.stdin:

        parts = line.split()
        if len(parts) >= 9:
            ip_address = parts[0]
            status_code = parts[-2]
            file_size = parts[-1]

            if ip_address.count('.') == 3 and status_code.isdigit() and \
                    file_size.isdigit():
                if status_code in status_codes:
                    status_count[status_code] += 1

                file_size = int(file_size)
                total_size += file_size

                line_count += 1

                if line_count % 10 == 0:
                    print("File size: {}".format(total_size))
                    for code in sorted(status_codes, key=lambda x: int(x)):
                        if status_count[code] > 0:
                            print("{}: {}".format(code, status_count[code]))

except KeyboardInterrupt:
    pass

finally:
    print("File size: {}".format(total_size))
    for code in sorted(status_codes, key=lambda x: int(x)):
        if status_count[code] > 0:
            print("{}: {}".format(code, status_count[code]))