pipeline {
    agent any
    
    environment {
        dockerImage = ''
        registry = "kshitizsaini113/testDocker"
        registryCredential = 'dockerHub'
    }
    
    stages {
        
        stage("Build Docker Image") {
            steps {
                script {
                    dockerImage = docker.build registry
                }
            }
        }
        
        stage("Upload to DockerHub") {
            steps {
                script {
                    docker.withRegistry("", registryCredential){
                        dockerImage.push()
                    }
                }
            }
        }
        
    }
}