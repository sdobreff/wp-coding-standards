<!-- Annotation has to be on the second line as errors are thrown on line 1 and errors on annotation lines are ignored. -->
phpcs:set WordPress.Files.FileName custom_test_classes[] \My_TestClass
<?php

namespace Plugin\Tests;

class TestSample extends My_TestClass {}
/* phpcs:set WordPress.Files.FileName custom_test_classes[] */
