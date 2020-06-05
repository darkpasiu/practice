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
                tests/tests --gtest_output="xml:gtestresults.xml"
                ls -la
                '''
                junit 'build/gtestresults.xml'
            }
        }
        stage('Code coverage') {
            steps {
                echo 'Code coverage..'
                sh '''
                mkdir -p build
                cd build
                make lcov
                '''
                // publish html
                publishHTML target: [
                    allowMissing: false,
                    alwaysLinkToLastBuild: false,
                    keepAll: true,
                    reportDir: 'build/lcoverage',
                    reportFiles: 'index.html',
                    reportName: 'LCov Report'
                ]
            }
        }
    }
    post { 
        always { 
            cleanWs()
        }
    }
}
