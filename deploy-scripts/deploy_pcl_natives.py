# Deploys the Maven artifacts containing the native libraries for pcl for each operating system/architecture to the maven-releases repository on the local Nexus server

import deploy_natives

def deploy():
    version = input("Enter the version of PCL: ")

    deploy_natives.deploy("win32", "x86", "pcl", version)
    deploy_natives.deploy("win32", "x86_64", "pcl", version)
    deploy_natives.deploy("linux", "x86", "pcl", version)
    deploy_natives.deploy("linux", "x86_64", "pcl", version)
    deploy_natives.deploy("macos", "", "pcl", version)

    return

deploy()
