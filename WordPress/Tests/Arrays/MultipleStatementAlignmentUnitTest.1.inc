<?php

/*
 * Test reporting and fixing "too much space before" errors in single line arrays.
 */
$array = array( 'b', 'd' ); // OK.
$array = array( 'a' => 'b', 'c' => 'd' ); // OK.
$array = array( 'a'    => 'b', 'c'               => 'd' ); // Bad x 2.

$array = array( 'a' /* Comment. */ => /* Comment. */ 'b' ); // OK.
$array = array( 'a' /* Comment. */    => /* Comment. */ 'b' ); // Bad.

$array = array( array( 'a' => 'b', 'c' => 'd' ) ); // OK.
$array = array( array( 'a'   => array( 'c'     => 'd' ) ) ); // Bad x 2.

/*
 * Test reporting errors and fixing double arrow alignment in a multi-line arrays.
 */
$array = array(
	'b',
	'd',
	// Something.
	'f',
);
$array = array(
	'a'   => 'b',
	'ccc' => 'd',
	'ee'  => 'f',
	'g'
		=> 'h',
);
$array = array(
	'a'   => 'b',
	123   => 'd',
	56958 => 'f',
	'g'
		=> 'h',
);

// Test no space before.
$array = array(
	'a'=> 'b', // Bad.
);
$array = array(
	'a'=> 'b', // Bad.
	'ccc'=> 'd', // Bad.
	'ee'=> 'f', // Bad.
	'g'
		=> 'h',
);

// Test too much space before.
$array = array(
	'a'        => 'b', // Bad.
);
$array = array(
	'a'             => 'b', // Bad.
	'ccc' => 'd',
	'ee'    => 'f', // Bad.
	'g'
		=> 'h',
);

// Test exact number of spaces before vs minimum.
$array = array(
	'a'     => 'b', // Bad.
	'ccc'   => 'd', // Bad.
	'ee'    => 'f', // Bad.
	'g'
		=> 'h',
);

// phpcs:set WordPress.Arrays.MultipleStatementAlignment exact false
$array = array(
	'a'        => 'b',
);
$array = array(
	'a'     => 'b',
	'ccc'   => 'd',
	'ee'    => 'f',
	'g'
		=> 'h',
);
$array = array(
	'a'  => 'b', // Bad.
	'ccc' => 'd',
	'ee'    => 'f', // Bad.
	'g'
			=> 'h',
);
$array = array(
	'a'	=> 'b', // Bad - also note: uses mid-line tab.
	'ccc'   => 'd',
	'ee'    => 'f',
	'g'
		      => 'h',
);
// phpcs:set WordPress.Arrays.MultipleStatementAlignment exact true


/*
 * Test dealing with new lines.
 */
$array = array(
	'a'
		=> 'b',
	'ccc'
		=> 'd',
);
// phpcs:set WordPress.Arrays.MultipleStatementAlignment ignoreNewlines false
$array = array(
	'a'
		=> 'b', // Bad.
	'ccc'
		=> 'd', // Bad.
);
// phpcs:set WordPress.Arrays.MultipleStatementAlignment ignoreNewlines true

// phpcs:set WordPress.Arrays.MultipleStatementAlignment exact false
// phpcs:set WordPress.Arrays.MultipleStatementAlignment ignoreNewlines false
// Test combined ignore new lines false + exact false.
$array = array(
	'a'     => 'b',
	'ccc'   => 'd',
	'ee'    => 'f',
	'g'
		=> 'h', // Bad.
);
$array = array(
	'a'  => 'b', // Bad.
	'ccc' => 'd',
	'ee'    => 'f', // Bad.
	'g'
				=> 'h', // Bad.
);
$array = array(
	'a'  => 'b', // Bad.
	'ccc' => 'd', // Bad.
	'ee'      => 'f',
	'g'
			  => 'h', // Bad.
);
$array = array(
	'a'  => 'b', // Bad.
	'ccc'   => 'd',
	'ee'    => 'f',
	'g'
		      => 'h', // Bad.
);
// phpcs:set WordPress.Arrays.MultipleStatementAlignment exact true
// phpcs:set WordPress.Arrays.MultipleStatementAlignment ignoreNewlines true


/*
 * Test with maxColumn value set.
 */
// phpcs:set WordPress.Arrays.MultipleStatementAlignment maxColumn 12
$array = array(
	'a'   => 'b',
	'ccc' => 'd',
	'ee'  => 'f',
	'gggggggggg' => 'h',
	'i'
		=> 'j',
	'kkkkkkkkkkkk'
				 => 'l',
);
$array = array(
	'a' => 'b', // Bad.
	'ccc' => 'd',
	'ee' => 'f', // Bad.
	'gggggggggg'=> 'h', // Bad - no space before.
);
$array = array(
	'a'            => 'b', // Bad.
	'ccc'          => 'd', // Bad.
	'ee'           => 'f', // Bad.
	'gggggggggg'   => 'h', // Bad - too much space before.
);
// phpcs:set WordPress.Arrays.MultipleStatementAlignment maxColumn 1000

// phpcs:set WordPress.Arrays.MultipleStatementAlignment exact false
// phpcs:set WordPress.Arrays.MultipleStatementAlignment maxColumn 12
// Test combined maxColumn value set + exact false.
$array = array(
	'a' => 'b',
);
$array = array(
	'a'    => 'b',
);
$array = array(
	'a'    => 'b',
	'ccc'  => 'd',
	'ee'   => 'f',
	'gggggggggg' => 'h',
	'i'
		=> 'j',
	'kkkkkkkkkkkk'
				 => 'l',
);

$array = array(
	'a'        => 'b', // Bad.
);
$array = array(
	'a'    => 'b',
	'ccc'  => 'd',
	'ee' => 'f', // Bad.
	'gggggggggg' => 'h',
);
$array = array(
	'a'    => 'b',
	'ccc'  => 'd',
	'ee'       => 'f', // Bad.
	'gggggggggg' => 'h',
);
$array = array(
	'a'        => 'b', // Bad.
	'ccc'      => 'd', // Bad.
	'ee'       => 'f', // Bad.
	'gggggggggg' => 'h',
);
// phpcs:set WordPress.Arrays.MultipleStatementAlignment exact true
// phpcs:set WordPress.Arrays.MultipleStatementAlignment maxColumn 1000

// phpcs:set WordPress.Arrays.MultipleStatementAlignment exact false
// phpcs:set WordPress.Arrays.MultipleStatementAlignment maxColumn 12
// phpcs:set WordPress.Arrays.MultipleStatementAlignment ignoreNewlines false
// Test combined maxColumn value set + exact false + ignore new lines false.
$array = array(
	'a'    => 'b',
	'ccc'  => 'd',
	'ee'   => 'f',
	'gggggggggg' => 'h',
	'i'
		=> 'j', // Bad.
	'kkkkkkkkkkkk'
				 => 'l', // Bad.
);
$array = array(
	'a'    => 'b',
	'ccc'  => 'd',
	'ee' => 'f', // Bad.
	'gggggggggg' => 'h',
	'i'
		=> 'j', // Bad.
	'kkkkkkkkkkkk'
				 => 'l', // Bad.
);
$array = array(
	'a'    => 'b',
	'ccc'  => 'd',
	'ee'       => 'f', // Bad.
	'gggggggggg'=> 'h', // Bad.
	'i'
		=> 'j', // Bad.
	'kkkkkkkkkkkk'
				 => 'l', // Bad.
);
$array = array(
	'a'        => 'b', // Bad.
	'ccc'      => 'd', // Bad.
	'ee'       => 'f', // Bad.
	'gggggggggg' => 'h',
	'i'
		=> 'j', // Bad.
	'kkkkkkkkkkkk'
				 => 'l', // Bad.
);
// phpcs:set WordPress.Arrays.MultipleStatementAlignment exact true
// phpcs:set WordPress.Arrays.MultipleStatementAlignment maxColumn 1000
// phpcs:set WordPress.Arrays.MultipleStatementAlignment ignoreNewlines true


/*
 * Test mixed complex array.
 */
$array = array(
	'a'   => 'b', // Bad.
	12345 => 'd', // Bad.
	'f',
	'g'
		=> 'h',
		array( 'something' ),
	array( 'a' => 'something' ),
	array(
		'a' => 'something',
	),
	'i' => array( 'something' ), // Bad.
			'jjjjjj' => array( 'a' => 'something' ),
	'kk' => array( // Bad.
		'a'     => 'something', // Bad.
	),
	$ab . 'l' => array( 'a' => 'something' ), // Bad.
	// Compound multi-line key.
	$ab .
	'l' => array( 'a' => 'something' ), // Bad.
		$ab . 'l' => array( 'a' => 'something' ), // Bad.
);


/*
 * Test multi-line array item handling. Default = always.
 */
$deprecated_functions = array(
	'the_category_head'           => array(
		'alt' => 'get_the_category_by_ID()',
	),
	'the_category_ID'             => function_call(
		$a,
		$b
	),
	'user_can_edit_post_comments' => 'multi-line
					string',
);
$deprecated_functions = array(
	'the_category_head' => array( // Bad.
		'alt' => 'get_the_category_by_ID()',
	),
	'the_category_ID'   => function_call( // Bad.
		$a,
		$b
	),
	'user_can_edit_post_comments'=> 'multi-line
					string', // Bad - no space.
	'the_category_ID'
	   => function_call( // Ok, ignore newline is being respected.
		$a,
		$b
	),
);

// phpcs:set WordPress.Arrays.MultipleStatementAlignment alignMultilineItems never

// OK - alignments to the expected column.
$deprecated_functions = array(
	'the_category_head'           => array(
		'alt' => 'get_the_category_by_ID()',
	),
	'the_category_ID'             => function_call(
		$a,
		$b
	),
	'user_can_edit_post_comments' => 'multi-line
					string',
);
// OK - alignments to index + 1.
$deprecated_functions = array(
	'the_category_head' => array(
		'alt' => 'get_the_category_by_ID()',
	),
	'the_category_ID' => function_call(
		$a,
		$b
	),
	'user_can_edit_post_comments' => 'multi-line
					string',
);
// OK - mixed alignments to index + 1 and expected column.
$deprecated_functions = array(
	'the_category_head'           => array(
		'alt' => 'get_the_category_by_ID()',
	),
	'the_category_ID' => function_call(
		$a,
		$b
	),
	'user_can_edit_post_comments' => 'multi-line
					string',
);

$deprecated_functions = array(
	'the_category_head'  => array( // Bad.
		'alt' => 'get_the_category_by_ID()',
	),
	'the_category_ID'=> function_call( // Bad.
		$a,
		$b
	),
	'user_can_edit_post_comments'    => 'multi-line
					string', // Bad.
);

// phpcs:set WordPress.Arrays.MultipleStatementAlignment alignMultilineItems sometimes
// Test invalid property value error.
$array = array(
	'a' => 'b',
);

// phpcs:set WordPress.Arrays.MultipleStatementAlignment alignMultilineItems =103
// Test invalid property value error.
$array = array(
	'a' => 'b',
);
// phpcs:set WordPress.Arrays.MultipleStatementAlignment alignMultilineItems !50
// Test invalid property value error.
$array = array(
	'a' => 'b',
);

// phpcs:set WordPress.Arrays.MultipleStatementAlignment alignMultilineItems <25

// OK - alignments to the expected column.
$deprecated_functions = array(
	'single1'    => 'something',
	'single12'   => 'something_else',
	'single123'  => 'something_else_again',
	'single1234' => 'another_something',
	'multi1'     => array(
		'alt' => 'current_user_can()',
	),
);

// Bad - 20% multi-line, alignment should be enforced.
$deprecated_functions = array(
	'single1' => 'something', // Bad.
	'single12' => 'something_else', // Bad.
	'single123' => 'something_else_again', // Bad.
	'single1234' => 'another_something',
	'multi1'   => array( // Bad.
		'alt' => 'current_user_can()',
	),
);

// Bad - more than 25% multi-line, alignment should be enforced for single line, key + 1/expected for multi-line.
$deprecated_functions = array(
	'single1' => 'something', // Bad.
	'single12' => 'something_else', // Bad.
	'single123' => 'something_else_again',
	'multi1'           => array( // Bad.
		'alt' => 'get_the_category_by_ID()',
	),
	'multi12'   => function_call( // OK - expected.
		$a,
		$b
	),
	'user_can_edit_post_comments' => 'multi-line
					string',
);
$deprecated_functions = array(
	'single1' => 'something', // Bad.
	'single12' => 'something_else',
	'multi1'   => array( // OK - expected.
		'alt' => 'get_the_category_by_ID()',
	),
	'multi12' => function_call( // OK - key + 1 .
		$a,
		$b
	),
	'user_can_edit_post_comments'    => 'multi-line
					string', // Bad.
);
$deprecated_functions = array(
	'multi1' => array(
		'alt' => 'get_the_category_by_ID()',
	),
	'multi12'    => function_call( // Bad.
		$a,
		$b
	),
	'user_can_edit_post_comments'=> 'multi-line
					string', // Bad - no space.
);

// phpcs:set WordPress.Arrays.MultipleStatementAlignment alignMultilineItems <=50%
// Test with value 50 and test validation for incorrectly passed % sign.

$deprecated_functions = array(
	'single1'                     => 'something',
	'single12'                    => 'something_else',
	'single123'                   => 'something_else_again',
	'multi1'                      => array(
		'alt' => 'get_the_category()',
	),
	'multi12'                     => function_call(
		$a,
		$b
	),
	'user_can_edit_post_comments' => 'multi-line
					string',
);

// Bad - 50% multi-line, alignment should be enforced.
$deprecated_functions = array(
	'single1' => 'something', // Bad.
	'single12' => 'something_else', // Bad.
	'single123' => 'something_else_again', // Bad.
	'multi1' => array( // Bad.
		'alt' => 'get_the_category_by_ID()',
	),
	'multi12' => function_call( // Bad.
		$a,
		$b
	),
	'user_can_edit_post_comments'=> 'multi-line
					string',  // Bad - no space.
);

// Bad - more than 50% multi-line, alignment should be enforced for single line, key + 1/expected for multi-line.
$deprecated_functions = array(
	'single1' => 'something', // Bad.
	'single12' => 'something_else',
	'multi1'                      => array( // Bad.
		'alt' => 'get_the_category_by_ID()',
	),
	'multi12'                     => function_call( // Bad.
		$a,
		$b
	),
	'user_can_edit_post_comments' => 'multi-line
					string',
);

$deprecated_functions = array(
	'multi1'   => array( // Bad.
		'alt' => 'get_the_category_by_ID()',
	),
	'multi12' => function_call(
		$a,
		$b
	),
	'user_can_edit_post_comments'=> 'multi-line
					string', // Bad - no space.
);

// phpcs:set WordPress.Arrays.MultipleStatementAlignment alignMultilineItems !=100

$deprecated_functions = array(
	'single1' => 'something', // Bad.
	'single12' => 'something_else', // Bad.
	'single1234' => 'another_something', // Bad.
	'multi12'             => function_call( // Bad.
		$a,
		$b
	),
	'user_can_edit_post_comments' => 'multi-line
					string',
);
$deprecated_functions = array(
	'single1' => 'something', // Bad.
	'single12' => 'something_else',
	'multi1'           => array( // Bad.
		'alt' => 'get_the_category_by_ID()',
	),
	'multi12'             => function_call( // Bad.
		$a,
		$b
	),
);
$deprecated_functions = array(
	'multi1' => array(
		'alt' => 'get_the_category_by_ID()',
	),
	'multi12' => function_call(
		$a,
		$b
	),
	'user_can_edit_post_comments' => 'multi-line
					string',
);

$deprecated_functions = array(
	'multi1'          => array( // Bad.
		'alt' => 'get_the_category_by_ID()',
	),
	'multi12'       => function_call( // Bad.
		$a,
		$b
	),
	'user_can_edit_post_comments'=> 'multi-line
					string', // Bad.
);

/*
 * This isn't actually testing something, but is the long version of the "short list" test.
 */
list(
	'prop1' => $prop1,
	'prop2'    => $prop2,
) = $some_var;

// phpcs:set WordPress.Arrays.MultipleStatementAlignment alignMultilineItems always

$array = array();

// Live coding/parse error.
// This has to be the last test in the file.
$array = array(
