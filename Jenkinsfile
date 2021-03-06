pipeline {
    agent any
    
    environment {
        dockerImage = ''
        registry = "kshitizsaini113/testdocker"
        registryCredential = 'dockerHub'
    }
    
    stages {
        
        stage("Build"){
            steps{
            echo "Build Stage"
            }
        }

        stage("Test"){
            steps{
            sh 'c++ ./src/test.cpp -o testFile.output'
            }
        }

        stage("Clean"){
            steps{
            sh './testFile.output'
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
                    docker.withRegistry("", registryCredential){
                        dockerImage.push()
                    }
                }
            }
        }
        
    }
}