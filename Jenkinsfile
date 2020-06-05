pipeline {
    options {
        buildDiscarder(logRotator(numToKeepStr: '20', artifactNumToKeepStr: '20'))
    }
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
                echo 'Run application'
                apps/app
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
                unit 'build/gtestresults.xml'
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
        stage('Valgrind') {
            steps {
                echo 'Static code check..'
                sh '''
                mkdir -p build
                cd build
                make valgrind
                '''
                publishValgrind (
                    failBuildOnInvalidReports: false,
                    failBuildOnMissingReports: false,
                    failThresholdDefinitelyLost: '',
                    failThresholdInvalidReadWrite: '',
                    failThresholdTotal: '',
                    pattern: 'build/valgrind/valgrind_memcheck.xml',
                    publishResultsForAbortedBuilds: false,
                    publishResultsForFailedBuilds: false,
                    sourceSubstitutionPaths: '',
                    unstableThresholdDefinitelyLost: '',
                    unstableThresholdInvalidReadWrite: '',
                    unstableThresholdTotal: '1'
                )
            }
        }
    }
    post { 
        always { 
            cleanWs()
        }
    }
}
