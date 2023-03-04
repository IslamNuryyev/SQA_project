# Backend - Phase 4

# -- File target notes --
# Format of the target txt files is as follows:
# "front_end\<txt file here>"

def main():
    print("hello world")

def readfile():
    file = open("front_end\items.txt", "r")
    print(file.read())
    return

main()
readfile()
