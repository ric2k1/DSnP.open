#!/usr/bin/env python3
'''
This self-checking program is designed by Chen, Jia-Shiuan.
If you have any questions, please contact class TAs or instructor.
All right reserved, DVLab, GIEE/EE, NTU.
Last Modified: 2018.10.18
'''
import os
from  subprocess import Popen, PIPE
import fnmatch

def toErrorStr ( s ):
    return "\033[31m\33[01m" + s +"\033[0m"

def toWarningStr ( s ):
    return "\033[93m\33[01m" + s +"\033[0m"

def toOkStr ( s ):
    return "\033[92m\33[01m" + s +"\033[0m"

def checkMust(MustExist, MustRemove):
    if not os.path.isfile(MustExist):
        return 1, toErrorStr("MustExist file \"" + MustExist + "\" not found !!")

    if not os.path.isfile(MustRemove):
        return 1, toErrorStr("MustRemove file \"" + MustRemove + "\" not found !!")
    return 0, ""

def check( tgzFile, MustExist, MustRemove):

    if not os.path.isfile(tgzFile):
        return 1, toErrorStr("tgz File \"" + tgzFile + "\" not found !!")

    baseName = os.path.basename(tgzFile)

    if baseName[-4:] != ".tgz":
        return 1, toErrorStr("Illegal File type \"" + baseName + "\"")

    process = Popen(["tar", "-ztf", tgzFile ], stdout=PIPE, stderr=PIPE)

    out, err = process.communicate()

    msg = ""

    if process.returncode :
        msg = toErrorStr("\nUntar Error !!\n\n") + \
              "Error Message: \n"  + \
                err.decode()
        return process.returncode, msg
    elif err :
        msg = toWarningStr("\nUntar Warning !!\033[0m\n\n") + \
              "Warning Message: \n"  + \
                err.decode()
	
    studentID = baseName.split('_')[0]
    fileList = [ x.lstrip("./") for x in out.decode().split()]
    MustExist = [ studentID+x for x in MustExist ]
    MustRemove = [ studentID+x for x in MustRemove ]

    for x in MustExist:
        if not fnmatch.filter(fileList, x) : 
            msg += toErrorStr("\nMissing MustExist File \"" + x + "\"\n")
            return 1, msg
        
    for x in fileList:
        if fnmatch.filter(MustRemove, x) : 
            msg += toErrorStr("\nMustRemove File \"" + x + "\" should be remove\n")
            return 1, msg

    HiddenFile = fnmatch.filter(fileList, "*/.*") + fnmatch.filter(fileList, ".*")
    if HiddenFile:
        msg +=  toWarningStr("\nWarning\033[0m\n\n") + \
                "Containing following unnecessary files: \n" + \
                '\n'.join(HiddenFile) + '\n'

    msg += toOkStr("\nself check pass !!\n")
    return 0, msg
    

if __name__ == '__main__':

    import sys
    from argparse import ArgumentParser

    parser = ArgumentParser(usage="SelfCheck <tgzFile> [-m MustExist MustRemove ] [-h]")

    parser.add_argument("tgzFile", help="the dircectory contains all tgz files")
    parser.add_argument(
        "-m", 
        metavar=("MustExist", "MustRemove"),
        help="path to MustExist and MustRemove",
        nargs=2,
        default=["./MustExist.txt", "./MustRemove.txt"],
        dest="must"
    )
    args = parser.parse_args()

    tgzFile       = args.tgzFile
    MustExist, MustRemove = args.must
    returnCode, msg = checkMust(MustExist, MustRemove)
    
    if returnCode:
        sys.exit(msg)
    else:
        MustExist  = open(MustExist).read().split()
        MustRemove = open(MustRemove).read().split()

    returnCode, msg = check( tgzFile, MustExist, MustRemove)

    if not returnCode:
        print(msg)
    else:
        print(msg, file=sys.stderr)
    
    
