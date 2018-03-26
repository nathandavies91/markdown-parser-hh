<?hh // strict

/**
 * Markdown Parser
 * @author Nathan Davies, http://nathandavies.ninja
 * @copyright Copyright (c) 2016, Nathan Davies
 */

namespace Markdown\Helpers;

use Markdown\Helper;
use Markdown\Interfaces\InlineElement;

class Reference extends Helper implements InlineElement
{
	/**
	 * @var array<string> Parser regex
	 * Example: [{content}]   =>   <span class="reference">[{content}]<span>
	 */
	public static array<string> $regex = array('/\[(?<content>[0-9]{1,})\]/');

	/**
	 * Markup for the reference tag
	 * @param array<string> $content Regex values: content
	 * @return string The markup
	 */
	public static function markup(array<string> $content) : string
	{
		return "<span class=\"reference\">[" . $content["content"] . "]</span>";
	}
}
