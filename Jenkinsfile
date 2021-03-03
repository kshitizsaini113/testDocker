pipeline {
    agent any
    
    environment {
        dockerImage = ""
        registry = "kshitizsaini113/mutex"
        registryCredential = dockerHub
    }
    
    stages {
        stage("Checkout") {
            steps {
                checkout([$class: 'GitSCM', branches: [[name: '*/master']], doGenerateSubmoduleConfigurations: false, extensions: [], submoduleCfg: [], userRemoteConfigs: [[credentialsId: 'gitHub', url: 'https://github.com/kshitizsaini113/Mutex-The-System-Metrics-Analyzer']]])
            }
        }
        
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
                    docker.withRegistry("", registryCredential)
                    dockerImage.push()
                }
            }
        }
        
    }
}