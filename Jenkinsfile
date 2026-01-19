pipeline {
    agent any

    stages {
        stage('Checkout') {
            steps {
                git branch: 'main',
                url: 'https://github.com/karlmage/jenkins-assignment.git', 
                credentialsId: 'github_karlmage'
            }
        }
        
        stage('Build') {
            steps {
                // Крок для збірки проекту з Visual Studio
                // Встановіть правильні шляхи до рішення/проекту та параметри MSBuild
                bat '"C:/Program Files/Microsoft Visual Studio/18/Community/MSBuild/Current/Bin/MSBuild.exe" test_repos.sln /t:Build /p:Configuration=Debug'
            }
        }

        stage('Test') {
            steps {
                // Команди для запуску тестів
                bat "x64\\Debug\\test_repos.exe --gtest_output=xml:test_report.xml"
            }
        }
    }

   post {
    always {
        echo 'Publishing Google Test results'
        junit allowEmptyResults: true, testResults: '**/test_report.xml'
    }
}

}