# Deploys the pcl-java-all module to the maven-releases repository on the local Nexus server

import os
import sys
from subprocess import call

def deploy():
    os.chdir(sys.path[0] + "/../pcl-java-all")
    call("mvn deploy", shell=True)

    return

deploy()