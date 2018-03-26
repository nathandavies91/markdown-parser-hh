<?hh // strict

/**
 * Markdown Parser
 * @author Nathan Davies, http://nathandavies.ninja
 * @copyright Copyright (c) 2016, Nathan Davies
 */

namespace Markdown\Helpers;

use Markdown\Helper;
use Markdown\Interfaces\InlineElement;

class Code extends Helper implements InlineElement
{
	/**
	 * @var array<string> Parser regex
	 * Example 1: ``  =>  `
	 * Example 2: `{content}`  =>  <code>{content}</code>
	 */
	public static array<string> $regex = array('/(``)/', '/(`)(?<code>.*?)\1/');

	/**
	 * Markup for the code element
	 * @param array<string> $content Regex values: code
	 * @return string The markup
	 */
	public static function markup(array<string> $content) : string
	{
		// Code block deliminator
		if ($content[1] == "``")
			return "&#96;";

		// Return code block
		return parent::markup($content["code"], "code");
	}
}
