<?hh // strict

/**
 * Markdown Parser
 * @author Nathan Davies, http://nathandavies.ninja
 * @copyright Copyright (c) 2016, Nathan Davies
 */

namespace Markdown\Helpers;

use Markdown\Helper;
use Markdown\Interfaces\InlineElement;

class Strong extends Helper implements InlineElement
{
	/**
	 * @var array<string> Parser regex
	 * Example: **{content}**   =>   <strong>{content}</strong>
	 */
	public static array<string> $regex = array('/([*_]){2}(?<content>.*?)\1{2}/');

	/**
	 * Markup for the strong element
	 * @param array<string> $content Regex values: content
	 * @return string The markup
	 */
	public static function markup(array<string> $content) : string
	{
		return parent::markup($content["content"], "strong");
	}
}
