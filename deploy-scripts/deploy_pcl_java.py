# Deploys the pom.xml file describing the pcl-java project to the maven-releases repository on the local Nexus server

import os
import sys
from subprocess import call

def deploy():
    os.chdir(sys.path[0] + "/..")
    call("mvn deploy", shell=True)

    return

deploy()