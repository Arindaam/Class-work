import re
import datetime
import sys
file1 = open(sys.argv[1], 'r') 
Lines = file1.readlines() 
adict={}
for line in Lines:
    pattern = re.compile("Starting Service|Ending Service")
    for match in re.finditer(pattern, line):
        m=line.split()
        if(m[4]=='Starting'):
            adict[m[6]]=[m[0],m[1]] #All Starting Services are added to a dict
        else:
            adict[m[6]].append(m[0]) # When we encouter the end, based on the starting time from dictionary, The Total time taken is calculated.
            adict[m[6]].append(m[1])
            FMT = "%Y-%m-%d %H:%M:%S.%f"
            time1= datetime.datetime.strptime(adict[m[6]][0] +" " +adict[m[6]][1],FMT) 
            time2= datetime.datetime.strptime(adict[m[6]][2] +" " +adict[m[6]][3],FMT) 
            duration= time2-time1
            days=duration.days * 86400  
            seconds=(duration.seconds + days)*1000
            milliseconds=duration.microseconds/1000
            total=seconds + milliseconds
            adict[m[6]].append(total)
for i in adict: 
    print(i,",",adict[i][0]," ",adict[i][1],",",adict[i][2]," ",adict[i][3],",",adict[i][4],sep='')
file1.close()   
