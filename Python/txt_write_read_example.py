
## OPEN WRITE
file = open("testfile.txt", "w")
## WRITE
file.write("Hello World\n")
file.write("This is our new text file\n")
file.write("and this is another line.\n")
file.write("Why? Because we can.")
# CLOSE
file.close()

## OPEN READ
file = open("testfile.txt", "r")
## READ
print(file.read())
## CLOSE
file.close()
