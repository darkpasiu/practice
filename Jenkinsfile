def summary

pipeline {
    options {
        buildDiscarder(logRotator(numToKeepStr: '20', artifactNumToKeepStr: '20'))
        disableConcurrentBuilds()
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
                    unstableThresholdTotal: ''
                )
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
                script {
                    summary = junit 'build/gtestresults.xml'
                    sh "echo All tests: ${summary.totalCount}, Failures: ${summary.failCount}, Skipped: ${summary.skipCount}, Passed: ${summary.passCount}"
                }
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
        stage('Deploy') {
            when {
                expression {
                    summary.failCount == 0
                }
            }
            steps {
                echo 'Deploying..'
                sh '''
                echo deploying into production
                '''
            }
        }
    }
    post {
        always {
            archiveArtifacts artifacts: 'build/apps/app', fingerprint: false
            cleanWs()
        }
    }
}
