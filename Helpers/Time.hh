<?hh // strict

/**
 * Markdown Parser
 * @author Nathan Davies, http://nathandavies.ninja
 * @copyright Copyright (c) 2016, Nathan Davies
 */

namespace Markdown\Helpers;

use Markdown\Helper;
use Markdown\Interfaces\InlineElement;

class Time extends Helper implements InlineElement
{
	/**
	 * @var array<string> Parser regex
	 * Example 1: @{content} {datetime={datetime}}@   =>   <time datetime="{datetime}">{content}</time>
	 * Example 2: @{content}@   =>   <time>{content}</time>
	 */
	public static array<string> $regex = array(
		'/(@)(?<content>.*?)\{datetime=(?<datetime>.*?)\}\1/',
		'/(@)(?<content>.*?)\1/'
	);

	/**
	 * Markup for the time element
	 * @param array<string> $content Regex values: content, ?datetime
	 * @return string The markup
	 */
	public static function markup(array<string> $content) : string
	{
		return "<time" . (($content["datetime"]) ? " datetime=\"" . $content["datetime"] . "\"" : null) . ">" . $content["content"] . "</time>";
	}
}
