#!/usr/bin/env python
 
from sys import argv
update_fd = open(argv[2], 'r')
 
permissions_count = 0
groups_count = 0
 
for normal_line in open(argv[1]):
    normal_filename = []
    normal_filename = normal_line.split("/", 1)
    normal_permissions = normal_line[:10]
    normal_groups = normal_line[13:22]
    update_fd.seek(0)
    for update_line in update_fd.readlines():
        update_line = update_line.strip()
        update_filename = update_line.split("/", 1)
        update_permissions = update_line[:10]
        update_groups = update_line[13:22]
        if normal_filename[1].strip() ==  update_filename[1].strip():
            if "firmware/image" in normal_line:
                break
            if normal_permissions != update_permissions:
                print "permissions diff"
                print "normal : " + normal_line.strip()
                print "update : " + update_line
                permissions_count += 1
            if normal_groups != update_groups:
                if "firmware/image" in normal_line:
                    break
                print "groups diff"
                print "normal : " + normal_line.strip()
                print "update : " + update_line
                groups_count += 1
            break
print ("permissions diff is ", permissions_count)
print ("groups diff is ", groups_count)

