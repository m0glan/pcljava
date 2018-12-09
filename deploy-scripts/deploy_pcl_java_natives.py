# Deploys the Maven artifacts containing the native libraries for pcl-java for each operating system/architecture to the maven-releases repository on the local Nexus server

import deploy_natives

def deploy():
    version = input("Enter the version of PCL Java: ")

    deploy_natives.deploy("win32", "x86", "pcl-java", version)
    deploy_natives.deploy("win32", "x86_64", "pcl-java", version)
    deploy_natives.deploy("linux", "x86", "pcl-java", version)
    deploy_natives.deploy("linux", "x86_64", "pcl-java", version)
    deploy_natives.deploy("macos", "", "pcl-java", version)

    return

deploy()