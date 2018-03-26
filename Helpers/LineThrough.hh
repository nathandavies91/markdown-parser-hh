<?hh // strict

/**
 * Markdown Parser
 * @author Nathan Davies, http://nathandavies.ninja
 * @copyright Copyright (c) 2016, Nathan Davies
 */

namespace Markdown\Helpers;

use Markdown\Helper;
use Markdown\Interfaces\InlineElement;

class LineThrough extends Helper implements InlineElement
{
	/**
	 * @var array<string> Parser regex
	 * Example: ~~{content}~~   =>   <del>{content}</del>
	 */
	public static array<string> $regex = array('/(\~){2}(?<content>.*?)\1{2}/');

	/**
	 * Markup for the line-through element
	 * @param array<string> $content Regex values: content
	 * @return string The markup
	 */
	public static function markup(array<string> $content) : string
	{
		return parent::markup($content["content"], "del");
	}
}
