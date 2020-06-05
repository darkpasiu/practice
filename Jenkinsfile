pipeline {
    agent any

    stages {
        stage('Compile') {
            steps {
                echo 'Building..'
                sh 'mkdir build'
                sh 'cd build'
                sh 'cmake ..'
                sh 'make app'
            }
        }
        stage('Test') {
            steps {
                echo 'Testing..'
            }
        }
        stage('Deploy') {
            steps {
                echo 'Deploying....'
            }
        }
    }
}
