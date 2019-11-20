find . -name "*.java" -exec sh -c "java -jar /opt/javaformat.jar {} > tmp && mv tmp {}" \; 
