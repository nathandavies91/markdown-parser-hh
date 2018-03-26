<?hh // strict

/**
 * Markdown Parser
 * @author Nathan Davies, http://nathandavies.ninja
 * @copyright Copyright (c) 2016, Nathan Davies
 */

namespace Markdown\Helpers;

use Markdown\Helper;
use Markdown\Interfaces\InlineElement;

class Highlight extends Helper implements InlineElement
{
	/**
	 * @var array<string> Parser regex
	 * Example: ***{content}***   =>   <mark>{content}</mark>
	 */
	public static array<string> $regex = array('/(\*){3}(?<content>.*?)\1{3}/');

	/**
	 * Markup for the highlight element
	 * @param array<string> $content Regex values: content
	 * @return string The markup
	 */
	public static function markup(array<string> $content) : string
	{
		return parent::markup($content["content"], "mark");
	}
}
