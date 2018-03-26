<?hh // strict

/**
 * Markdown Parser
 * @author Nathan Davies, http://nathandavies.ninja
 * @copyright Copyright (c) 2016, Nathan Davies
 */

namespace Markdown\Helpers;

use Markdown\Helper;
use Markdown\Interfaces\InlineElement;

class Emphasis extends Helper implements InlineElement
{
	/**
	 * @var array<string> Parser regex
	 * Example: *{content}*   =>   <em>{content}</em>
	 */
	public static array<string> $regex = array('/([*_])(?<content>.*?)\1/');

	/**
	 * Markup for the emphasis element
	 * @param array<string> $content Regex values: content
	 * @return string The markup
	 */
	public static function markup(array<string> $content) : string
	{
		return parent::markup($content["content"], "em");
	}
}
