pipeline {
    agent any

    stages {
        stage('Compile') {
            steps {
                echo 'Building..'
                sh '''
                mkdir -p build
                cd build
                cmake ..
                make app
                '''
            }
        }
        stage('Test') {
            steps {
                echo 'Testing..'
                sh '''
                mkdir -p build
                cd build
                make tests
                '''
            }
        }
        stage('Deploy') {
            steps {
                echo 'Deploying....'
            }
        }
    }
    post { 
        always { 
            cleanWs()
        }
    }
}
