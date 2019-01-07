# Deploys the natives for a certain operating system, architecture, library and version to the maven-releases repository on the local Nexus server

import os
import sys 
from subprocess import call
import config

def deploy(opsys, arch, lib, version):
    path = sys.path[0] + "/../lib/natives/" + opsys + "/" + arch + "/" + lib

    if os.path.exists(path):
        os.chdir(path)

        bundleNativesCmd = "jar cMf natives.jar ."
        deployNativesCmd = "mvn deploy:deploy-file -DgroupId=com.movlad.pcl-java -DartifactId=natives-" + lib + "-" + opsys + "-" + arch + " -Dclassifier=natives-" + lib + " "

        deployNativesCmd += "-Dversion=" + version + " "
        deployNativesCmd += "-DgeneratePom=true "
        deployNativesCmd += "-Dpackaging=jar "
        deployNativesCmd += "-DrepositoryId=" + config.MAVEN_REPOSITORY_ID + " "
        deployNativesCmd += "-Durl=" + config.MAVEN_URL + " "
        deployNativesCmd += "-Dfile=natives.jar"

        call(bundleNativesCmd, shell=True)
        call(deployNativesCmd, shell=True)

        os.remove("natives.jar")

    return
